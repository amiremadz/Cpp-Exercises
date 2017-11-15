#ifndef __TICTACTOE_HPP__
#define __TICTACTOE_HPP__

#include <iostream>
#include <string>
#include "Gameboard.hpp"

using namespace std;

class Tictactoe{
    private:
        string player_1;
        string player_2;
        Gameboard board;

    public:
        Tictactoe();

    public:
        void play(); 
        string getPlayer1Name();
        string getPlayer2Name();
};

Tictactoe::Tictactoe(){
    cout << "Enter Player 1 name: " << flush;
    cin >> player_1;
    cout << endl;
    cout << "Enter Player 2 name: " << flush;
    cin >> player_2;
    cout << endl;
}

string Tictactoe::getPlayer1Name(){
    return player_1;
}

string Tictactoe::getPlayer2Name(){
    return player_2;
}

void Tictactoe::play(){
    int row, col;
    char symbol_1 = 'x';
    char symbol_2 = 'o';

    do {

        do {
            cout << "Player 1, Enter row and column:" << endl;
            cout << "row column: " << flush;
            cin >> row;
            cin >> col;
        } while (board.getGameSpace(row, col) != '-');

        board.setGameSpace(row, col, symbol_1);
        board.printInfo();

        if(board.fourInRow(symbol_1) || board.fourInColumn(symbol_1) || board.fourInDiagonal(symbol_1)){
            cout << "Player 1 won!" << endl;
            return;
        }
        
        do {
            cout << "Player 2, Enter row and column:" << endl;
            cout << "row column: " << flush;
            cin >> row;
            cin >> col;
        } while (board.getGameSpace(row, col) != '-');

        board.setGameSpace(row, col, symbol_2);
        board.printInfo();
        
        if(board.fourInRow(symbol_2) || board.fourInColumn(symbol_2) || board.fourInDiagonal(symbol_2)){
            cout << "Player 2 won!" << endl;
            return;
        }
    } while(! board.isFilled());    
    
    cout << "Tie game!" << endl;
}


#endif
