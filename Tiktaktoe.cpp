// This is a program that uses C++ to create a TikTakToe.
// mkuangdotcom 

#include <iostream>
using namespace std;

int OneUntilNine();
void Display(char,char,char,char,char,char,char,char,char);
bool WhoWin(char,char,char,char,char,char,char,char,char);
int Occupied(char,char,char,char,char,char,char,char,char,char);

int main() {
  int move;
  char decision;

  do {
     char box1 = ' ', box2 = ' ', box3 = ' ',
          box4 = ' ', box5 = ' ', box6 = ' ',
          box7 = ' ', box8 = ' ', box9 = ' ';
     bool endGame = false;
     bool Xplayer = false;
     bool Oplayer = false;
     int boxTransfer;

     while (endGame == false) {
        // Player X move
        Display(box1,box2,box3,box4,box5,box6,box8,box8,box9);
        cout << "Player X choose box (1-9): ";
        move = OneUntilNine();

        boxTransfer =
        Occupied(move,box1,box2,box3,box4,box5,box6,box7,box8,box9);
        if (boxTransfer == 1)      box1 = 'X';
        else if (boxTransfer == 2) box2 = 'X';
        else if (boxTransfer == 3) box3 = 'X';
        else if (boxTransfer == 4) box4 = 'X';
        else if (boxTransfer == 5) box5 = 'X';
        else if (boxTransfer == 6) box6 = 'X';
        else if (boxTransfer == 7) box7 = 'X';
        else if (boxTransfer == 8) box8 = 'X';
        else if (boxTransfer == 9) box9 = 'X';

        Xplayer = WhoWin(box1,box2,box3,box4,box5,box6,box7,box8,box9);
        if (Xplayer == true) {
          cout << "\t **PLAYER X WINS!!**" << endl << endl;
          Display(box1,box2,box3,box4,box5,box6,box7,box8,box9);
          endGame = true;
          break;
        }

        if (box1!=' ' && box2!=' ' && box3!=' ' && box4!=' ' && box5!=' '
        && box6!=' ' && box7!=' ' && box8!=' ' && box9!=' ') {
          cout << "\t  **DRAW!!**" << endl << endl;
          Display(box1,box2,box3,box4,box5,box6,box7,box8,box9);
          endGame = true;
          break;
        }

        // Player O move
        Display(box1,box2,box3,box4,box5,box6,box7,box8,box9);
        cout << "Player O choose box (1-9): ";
        move = OneUntilNine();

        boxTransfer =
        Occupied(move,box1,box2,box3,box4,box5,box6,box7,box8,box9);
        if (boxTransfer == 1)      box1 = 'O';
        else if (boxTransfer == 2) box2 = 'O';
        else if (boxTransfer == 3) box3 = 'O';
        else if (boxTransfer == 4) box4 = 'O';
        else if (boxTransfer == 5) box5 = 'O';
        else if (boxTransfer == 6) box6 = 'O';
        else if (boxTransfer == 7) box7 = 'O';
        else if (boxTransfer == 8) box8 = 'O';
        else if (boxTransfer == 9) box9 = 'O';

        Oplayer = WhoWin(box1,box2,box3,box4,box5,box6,box7,box8,box9);
        if (Oplayer == true) {
          cout << "\t **PLAYER O WINS!!**" << endl << endl;
          Display(box1,box2,box3,box4,box5,box6,box7,box8,box9);
          endGame = true;
          break;
        }

        if (box1!=' ' && box2!=' ' && box3!=' ' && box4!=' ' && box5!=' '
        && box6!=' ' && box7!=' ' && box8!=' ' && box9!=' ') {
          cout << "\t  **DRAW!!**" << endl <<endl;
          Display(box1,box2,box3,box4,box5,box6,box7,box8,box9);
          endGame = true;
          break;
        } 
    }

    cout << "Do you want to play again?? (Yes for any key and N/n for NO):";
    cin >> decision;
  } while (decision != 'n' && decision != 'N');

    cout << "\t **BYE**" << endl << endl;
    return 0; 
    }

    int OneUntilNine() {
        int input;

    while (!(cin >> input) || input < 1 || input > 9) {
        cin.clear();
        cin.ignore(99,'\n');
        cout << "  *Wrong input. Try again: ";
    }
    return input; 
}
    
    void Display(char box1,char box2,char box3,char box4,char box5,char
    box6,char box7,char box8,char box9) {
        cout << endl << "Noughts & Crosses";
        cout << "\t   Numbers that represent each box" << endl;
        cout << "  +---+---+---+" << "\t\t\t   +---+---+---+" << endl;
        cout << "  | "<<box1<<" | " << box2 << " | "<< box3 << " | " << "\t\t   | 1 | 2 | 3 |" << endl;
        cout << "  +---+---+---+" << "\t\t\t   +---+---+---+" << endl;
        cout << "  | "<<box4<<" | " << box5 << " | "<< box6 << " | " << "\t\t   | 4 | 5 | 6 |" << endl;
        cout << "  +---+---+---+" << "\t\t\t   +---+---+---+" << endl;
        cout << "  | "<<box7<<" | " << box8 << " | "<< box9 << " | " << "\t\t   | 7 | 8 | 9 |" << endl;
        cout << "  +---+---+---+" << "\t\t\t   +---+---+---+" << endl << endl;
}

int Occupied(char move,char box1,char box2,char box3,char box4,char
box5,char box6,char box7,char box8,char box9) {
  bool infinity = true;
  
  while (infinity == true) {
     if (move == 1 && box1 == ' ')
        return 1;
     else if (move == 1 && box1 != ' ') {
        cout << "Already used. Choose again: ";
        move = OneUntilNine();
     }
     if (move == 2 && box2 == ' ')
        return 2;
     else if (move == 2 && box2 != ' ') {
        cout << "Already used. Choose again: ";
        move = OneUntilNine();
     }
     if (move == 3 && box3 == ' ')
        return 3;
     else if (move == 3 && box3 != ' ') {
        cout << "Already used. Choose again: ";
        move = OneUntilNine();
     }
     if (move == 4 && box4 == ' ')
        return 4;
     else if (move == 4 && box4 != ' ') {
        cout << "Already used. Choose again: ";
        move = OneUntilNine();
     }
     if (move == 5 && box5 == ' ')
        return 5;
     else if (move == 5 && box5 != ' ') {
        cout << "Already used. Choose again: ";
        move = OneUntilNine();
     }
     if (move == 6 && box6 == ' ')
        return 6;
     else if (move == 6 && box6 != ' ') {
        cout << "Already used. Choose again: ";
        move = OneUntilNine();
     }
     if (move == 7 && box7 == ' ')
                return 7;
     else if(move == 7 && box7 != ' ') {
        cout << "Already used. Choose again: ";
        move = OneUntilNine();
     }
     if (move == 8 && box8 == ' ')
        return 8;
     else if (move == 8 && box8 != ' ') {
        cout << "Already used. Choose again: ";
        move = OneUntilNine();
     }
     if (move == 9 && box9 == ' ')
        return 9;
     else if (move == 9 && box9 != ' ') {
        cout << "Already used. Choose again: ";
        move = OneUntilNine();
     }
}
  return 'E'; //error!
}

bool WhoWin(char box1,char box2,char box3,char box4,char box5,char box6,char
box7,char box8,char box9) {
  if (box1 != ' ' && box1 == box2 && box1 == box3)      return true;
  else if (box4 != ' ' && box4 == box5 && box4 == box6) return true;
  else if (box7 != ' ' && box7 == box8 && box7 == box9) return true;
  else if (box1 != ' ' && box1 == box4 && box1 == box7) return true;
  else if (box2 != ' ' && box2 == box5 && box2 == box8) return true;
  else if (box3 != ' ' && box3 == box6 && box3 == box9) return true;
  else if (box1 != ' ' && box1 == box5 && box1 == box9) return true;
  else if (box3 != ' ' && box3 == box5 && box3 == box7) return true;
  return false;
}
