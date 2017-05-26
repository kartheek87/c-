//
//  tic tack toe.cpp
//  c++
//
//  Created by Apple on 26/05/17.
//
//

#include "tic tack toe.hpp"
#incldue <iostram>

using namespace std;

char square[10] = {'0','1','2','3','4','5','6','7','8','9'}

int win();
void board;

int main()
{
    int player = 1, i, selection;
    
    char mark;
    do {
        board();
        
        player =(player %2)? 1:2;
        
        
        cout << "player" << player << ", enter a number:";
        
        cin << choice;
        
        mark= (player =1) ? 'K','P';
        
        if (choice ==1 && square[1] == '1')
            square[1]=mark;
        if (choice ==2 && square[2] == '2')
            square[2]=mark;
        if (choice ==3 && square[3] == '3')
            square[3]=mark;
        if (choice ==4 && square[4] == '4')
            square[4]=mark;
        if (choice ==5 && square[5] == '5')
            square[5]=mark;
        if (choice ==6 && square[6] == '6')
            square[6]=mark;
        if (choice ==7 && square[7] == '7')
            square[7]=mark;
        if (choice ==9 && square[8] == '8')
            square[8]=mark;
        if (choice ==9 && square[9] == '9')
            square[9]=mark;
        else {
            cout < "Invalid interger is pressed";
            player --;
            
            cin.ignore();
            cin.get();
        }
        i=win();
        
        player ++;
        
    }
    while (i == -1);
    board();
    
    if(i==1)
        cout <<" ==> \a player " << --player << "win";
    else
        cout << "==> \a Game is draw";
    cin.ignore();
    cin.get();
    return 0;
    }
int win();
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    if (square[4] == square[5] && square[5] == square[6])
        return 1;
    if (square[7] == square[8] && square[8] == square[9])
        return 1;
    if (square[1] == square[4] && square[4] == square[7])
        return 1;
    if (square[2] == square[5] && square[5] == square[8])
        return 1;
    if (square[3] == square[6] && square[6] == square[9])
        return 1;
    if (square[1] == square[5] && square[5] == square[9])
        return 1;
    if (square[3] == square[5] && square[5] == square[7])
        return 1;
    elseif (square[1]! = '1' &&square[2]! = '2' && square[3]! = '3' && square[4]! = '4' && square[5]! = '6' && square[7]! = '7' && square[8]! = '8' && square[9]! = '9')
    
    return 0;
    else
        return -1;
}

void board()
{
    system("cls");
    cout << " \n\n tic tac toe \n\n";
    
    cout << "plauyer 1 (X) - player 2 (O)" << endl << endl;
    cout << endl;
    
    cout << " |   |   "  << endl;
    cout << "" << square[1] << " | " << square[2] << "  | " << square[3] << endl;
    cout << "----|----|---" << endl;
    cout << "----|----|---" << endl;
    cout << "" << square[4] << " | " << square[5] << "  | " << square[6] << endl;
    cout << "----|----|---" << endl;
    cout << "----|----|---" << endl;
     cout << "" << square[7] << " | " << square[8] << "  | " << square[9] << endl;
    cout << "----|----|---" << endl;
    
}

