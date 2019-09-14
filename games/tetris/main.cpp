#include <iostream>
#include <vector>
#include <string>
#include <termios.h>
#include <unistd.h>

char getch() 
{
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
            perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
            perror ("tcsetattr ~ICANON");
    return (buf);
}

// tetromino matrix width/height
const int W = 4;

const int nScreenWidth = 80;
const int nScreenHeight = 30;
const int nScreenLength = nScreenWidth * nScreenHeight;

const int nFieldWidth = 12;
const int nFieldHeight = 18;
 
bool gameOver;

std::vector<std::string> tetromino(7);
std::vector<unsigned char> pField(nFieldWidth * nFieldHeight);
std::vector<char> screen(nScreenLength, ' ');

int rotate(int pX, int pY, int r)
{
    int pI;

    switch (r % 4)
    {
        // 0 degrees
        case 0:
            pI = pY * W + pX;
            break;
        // 90 degrees
        case 1:
            pI = (W - 1 - pX) * W + pY;
            break;
        // 180 degrees    
        case 2:
            pI = (W - 1 - pY) * W + (W - 1 - pX);
            break;
        // 270 degrees    
        case 3: 
            pI = pX * W + (W - 1 - pY);
            break;
    }

    return pI;
}

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

void setup()
{
    gameOver = false;
    make_tetrominos(tetromino);

    for (int x = 0; x < nFieldWidth; ++x)
    {
        for (int y = 0; y < nFieldHeight; ++y)
        {
            pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0; 
        }
    }
}


void draw()
{
    // draw field
    std::string key{" ABCDEFG=#"};
    const int offset = 2;

    for (int x = 0; x < nFieldWidth; ++x)
    {
        for (int y = 0; y < nFieldHeight; ++y)
        {
            int idx = pField[y * nFieldWidth + x];
            screen[(y + offset) * nScreenWidth + (x + offset)] = key[idx];
        }
    }

    for (int x = 0; x < nScreenWidth; ++x)
    {
        for (int y = 0; y < nScreenHeight; ++y)
        {
            std::cout << screen[y * nScreenWidth + x];
        }
        std::cout << std::endl;
    }

}

void logic() {};

void input() {};

int main()
{
    setup();
    {
        draw();
        input();
        logic();
    }

    std::cout << "Exit!" << std::endl;
    return 0;
}

















