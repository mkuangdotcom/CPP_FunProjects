#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int STORE = 5;
const int MONTHS = 12;

void readFile(string, double [][MONTHS], string store[]);
double grandTotalSales(double [][MONTHS]);
double averageMonthlySales(double [][MONTHS]);
double monthTotalSales(double [][MONTHS], int);
double storeTotalSales(double [][MONTHS], int);
double storeTotalSales(double [][MONTHS], int);
void indicesOfHighestSales(double [][MONTHS],int& ,int&);


int main () {
    double salesData[STORE][MONTHS];
    string store[STORE];
    string fileName;
    string fileExport;
    double avgMonth[MONTHS];
    string nameMonth[MONTHS] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int higehstIndex = 0, highestStore = 0;
    double largest;

    cout << "Enter the file name for input: ";
    cin >> fileName;

    readFile(fileName, salesData, store);
    grandTotalSales(salesData);
    averageMonthlySales(salesData);
    
    cout << "Enter the file name for the output: ";
    cin >> fileExport;

    fstream outFile(fileExport, ios::out);
    outFile << fixed << setprecision(2) << right;
    outFile << "Grand total of sales over all stores: RM" << setw(10) << grandTotalSales(salesData) << endl;
    outFile << "Average sales per month:              RM" << setw(10) << averageMonthlySales(salesData) << endl << endl;

    outFile << "The highest sales: " << endl;
    outFile << "----------------" << endl;
    indicesOfHighestSales(salesData, higehstIndex, highestStore);
    outFile << "Store: " << setw(10) << store[highestStore] << endl;
    outFile << "Month: " << setw(10) << nameMonth[higehstIndex] << endl;
    outFile << "Sales: " << setw(10) << largest << endl << endl;

    outFile << "Total sales by month: " << endl;
    outFile << setw(10) << "------" << setw(10) << "-----" << endl;
    for (int c = 0; c < MONTHS; c++) {
        outFile << setw(10) << nameMonth[c] << "RM " << setw(10) << monthTotalSales(salesData, c) << endl;
    }
    outFile << endl;


    outFile << "Total sales by store: ";
    outFile << setw(10) << "Store" << setw(10) << "Total Sales" << endl;
    outFile << setw(10) << "-----" << setw(10) << "-----------" << endl;
    for (int r = 0; r < STORE; r++) {
        outFile << setw(10) << store[r] << "RM" << setw(10) << storeTotalSales(salesData, r) << endl;
    }
    outFile << endl;

    outFile << "Profitable stores: " << endl;
    outFile << "-----------------" << endl;
    for (int r = 0; r < STORE; r++) {
        if (storeTotalSales(salesData, r) > 600000.00)
            outFile << store[r] << endl;
    }

    return 0;
}


void readFile(string fileName, double salesData[][MONTHS], string store[]) {
    fstream inFile(fileName, ios::in);
    int s;

    if (!inFile) {
        cout << "Error opening the file!";
        exit(1);
    } else {
        for (int r = 0; r < STORE; r++) {
            for (int c = 0; c < MONTHS; c++) {
                inFile >> s;
                salesData[r][c] = s * 1000.00;
            }
        }
        for (int r = 0; r < STORE; r++) {
            inFile >> store[r];
        }
    }
}

double grandTotalSales(double salesData[][MONTHS]) {
    double sum = 0.0;

    for (int r = 0; r < STORE; r++) {
        for (int c = 0; c < MONTHS; c++) {
            sum += salesData[r][c];
        }
    }

    return sum;
}

double averageMonthlySales(double salesData[][MONTHS]) {
    double avgMonth[MONTHS];
    double sum = grandTotalSales(salesData);

    return sum / 12.0;
}

double monthTotalSales(double salesData[][MONTHS], int c) {
    double sumMonth = 0.0;
     for (int r = 0; r < STORE; r++) {
        sumMonth += salesData[r][c];
    }

    return sumMonth;
}

double storeTotalSales(double salesData[][MONTHS], int r) {
    double sumStore;
    for (int c = 0; c < MONTHS; c++) {
        sumStore += salesData[r][c];
    }

    return sumStore;
}

void indicesOfHighestSales(double salesData[][MONTHS], int& highestIndex, int& highestStore) {
    double largest = salesData[0][0];

    for (int r = 0; r < STORE; r++) {
        for (int c = 0; c < MONTHS; c++) {
            if (salesData[r][c] > largest) {
                largest = salesData[r][c];
                highestIndex = r ;
                highestStore = c;
            }
        }
    }
}
