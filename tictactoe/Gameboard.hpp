#ifndef __GAMEBOARD_HPP__
#define __GAMEBOARD_HPP__
using namespace std;

class Gameboard{
    private:
        char gameboard[4][4];
        int numOfFilled{0};

    public:
        Gameboard();    

    public:
        void setGameSpace(int row, int column, char value);
        char getGameSpace(int row, int column);
        void printInfo();
        bool fourInRow(char value);
        bool fourInColumn(char value);
        bool fourInDiagonal(char value);    
        bool isFilled();
};



#endif
