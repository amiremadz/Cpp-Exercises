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

    private:
        bool checkIfWin(char symbol);    
        void getUserInput(Gameboard board, char symbol, int &row, int &col);
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

bool Tictactoe::checkIfWin(char symbol){
    bool win = board.fourInRow(symbol) || board.fourInColumn(symbol) || board.fourInDiagonal(symbol);
    return win;
}

void Tictactoe::getUserInput(Gameboard board, char symbol, int &row, int &col){
    do {
        bool row_correct = false;
        bool col_correct = false;
        do {
            cout << "Player "<< symbol << " Enter row, column: " << flush;
            cin >> row;
            cin >> col;

            row_correct = (row >= 0) && (row < 4);
            col_correct = (col >= 0) && (col < 4);
        } while (!row_correct || !col_correct);
    } while (board.getGameSpace(row, col) != '-');
}

void Tictactoe::play(){
    int row, col;
    char symbol_1 = 'x';
    char symbol_2 = 'o';

    do {
        char symbol = symbol_1;
        getUserInput(board, symbol, row, col);
        board.setGameSpace(row, col, symbol);
        board.printInfo();

        if(checkIfWin(symbol)){
            cout << "Player 1 won!" << endl;
            return;
        }

        symbol = symbol_2;
        getUserInput(board, symbol, row, col);
        board.setGameSpace(row, col, symbol);
        board.printInfo();
        
        if(checkIfWin(symbol)){
            cout << "Player 2 won!" << endl;
            return;
        }
    } while(! board.isFilled());    
    
    cout << "Tie game!" << endl;
}


#endif
