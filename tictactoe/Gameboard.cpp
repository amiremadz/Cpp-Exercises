#include "Gameboard.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Gameboard::Gameboard(){
    for(int row = 0; row < 4; row++){
        for(int col = 0; col < 4; col++){
            gameboard[row][col] = '-';
        }
    }
};

void Gameboard::setGameSpace(int row, int column, char value){
    gameboard[row][column] = value;
    numOfFilled++;
}

char Gameboard::getGameSpace(int row, int column){
    return gameboard[row][column];
}

bool Gameboard::fourInRow(char value){
    for(int row = 0; row < 4; ++row){
        int count = 0;
        for(int col = 0; col < 4; col++){
            if(gameboard[row][col] == value){
                count++;
            }
        }
        if(count == 4){
            return true;
        }
    }
    return false;
}

bool Gameboard::fourInColumn(char value){
    for(int col = 0; col < 4; col++){
        int count = 0;
        for(int row = 0; row < 4; row++){
            if(gameboard[row][col] == value){
                count++;
            }
        }
        if(count == 4){
            return true;
        }
    }
    return false;
}

bool Gameboard::fourInDiagonal(char value){
    int count1 = 0;
    int count2 = 0;
    for(int diag = 0; diag < 4; diag++){
       if(gameboard[diag][diag] == value){
           count1++;        
       }
        
       if(gameboard[diag][3-diag] == value){
           count2++;
       }
    }
    if((count1 == 4) || (count2 == 4)){
        return true;
    }
        
    return false;
}

bool Gameboard::isFilled(){
    if(numOfFilled == 16){
        return true;
    }
    return false;
}


void Gameboard::printInfo(){
   for(int row = 0; row < 4; row++){
       for(int col = 0; col < 4; col++){
           cout << setw(4) << gameboard[row][col] << flush; 
       }
       cout << endl;
    }
}


