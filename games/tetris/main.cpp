#include <iostream>
#include <vector>
#include <string>


void make_tetrominos(std::vector<std::string> &tetromino)
{
    tetromino[0] = "..X...X...X...X.";
    tetromino[1] = "..X..XX...X.....";
    tetromino[2] = ".....XX..XX.....";
    tetromino[3] = "..X..XX..X......";
    tetromino[4] = ".X...XX...X.....";
    tetromino[5] = ".X...X...XX.....";
    tetromino[6] = "..X...X..XX.....";
}


int main()
{
    std::vector<std::string> tetromino(7);
    make_tetrominos(tetromino);

    std::cout << "Exit!" << std::endl;
    return 0;
}
