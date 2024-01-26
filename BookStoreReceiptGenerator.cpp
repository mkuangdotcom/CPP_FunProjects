#include <iostream>
#include <fstream>
using namespace std;

struct Purchase{
  string bookCode, bookTitle;
  int bookUnit;
  float bookPrice;
};


void generatePurchaseArray(string filename, int *num, Purchase parray[]) 
{
  fstream inputfile;
  Purchase p;
  int x=0;

  cout << "Filename:" << filename << endl;

  inputfile.open(filename, ios::in);

  while (inputfile) {
    inputfile >> p.bookCode >> p.bookUnit >> p.bookPrice >>
p.bookTitle;
  
    if (!inputfile.eof()) {
      parray[x].bookCode = p.bookCode;
      parray[x].bookUnit = p.bookUnit;
      parray[x].bookPrice = p.bookPrice;
      parray[x].bookTitle = p.bookTitle;
      x++;
    } 
  }
  *num = x;
}

int getTotal(int x, Purchase parray[]) {
    int i;
    int total=0;

    for (i=0; i<x; i++)
        total += parray[i].bookUnit * parray[i].bookPrice;
    return total;
}

void printReceipt(int x, Purchase parray[]) {
    int i;
  
    cout << "Purchase Receipt" << endl;
    cout << "~~~~~~~~~~~~~~~~" << endl;

    for (i=0; i<x; i++) {
        cout << "Item : " << i+1 << endl;
        cout << "Item Code : " << parray[i].bookCode << endl;
        cout << "Book Title : " << parray[i].bookTitle << endl;
        cout << "Book Price : " << parray[i].bookPrice << endl;
        cout << "Quantity : " << parray[i].bookUnit << endl;
        cout << "Subtotal : " << parray[i].bookPrice * parray[i].bookUnit
<< endl << endl;
    }
    cout << "Total Amount: " << getTotal(x,parray) << endl;
    cout << endl;
    cout << "Thank you and Please Come Again!!" << endl;
}


int main () 
{
    int numberOfBook;
    Purchase purchaseArray[10];
    string purchasefile;

    cout <<"Type in filename of purchase list: ";
    cin >> purchasefile;
    generatePurchaseArray(purchasefile, &numberOfBook, purchaseArray); 
    printReceipt(numberOfBook, purchaseArray);
    return 0;   
    }
