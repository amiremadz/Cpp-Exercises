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

const int nFieldWidth = 12;
const int nFieldHeight = 18;
 
const int offset = 4;

const int nScreenLength = (nScreenWidth + offset) * (nScreenHeight + offset);

bool bGameOver;

std::vector<std::string> tetromino(7);
std::vector<int> pField(nFieldWidth * nFieldHeight);
std::vector<char> screen(nScreenLength, ' ');

int nCurrentPiece;
int nCurrentRotation;
int nCurrentX;
int nCurrentY;

char inputKey;

enum class Direction {LEFT, RIGHT, DOWN, ROTATE, UNDEFINED};
Direction dir;

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

// nPosX: x coordinate of top left corner
// nPosY: y coordinate of top left corner
bool doesPeiceFit(int nTetromino, int nRotation, int nPosX, int nPosY)
{
    for (int pX = 0; pX < 4; ++pX)
    {
        for (int pY = 0; pY < 4; ++pY)
        {
            // index into piece
            int pI = rotate(pX, pY, nRotation);
              
            // index into field
            int pXField = nPosX + pX;
            int pYField = nPosY + pY;

            int fI = pYField * nFieldWidth + pXField;

            if (pXField >= 0 && pXField < nFieldWidth && pYField >= 0 && pYField < nFieldHeight)
            {
                if (tetromino[nTetromino][pI] == 'X' && pField[fI] != 0)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

void setup()
{
    bGameOver = false;
    nCurrentPiece = 0;
    nCurrentRotation = 0;
    nCurrentX = nFieldWidth / 2;
    nCurrentY = 0;

    make_tetrominos(tetromino);

    for (int x = 0; x < nFieldWidth; ++x)
    {
        for (int y = 0; y < nFieldHeight; ++y)
        {
            pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0; 
        }
    }
}

void drawField()
{
    std::string key{" ABCDEFG=#"};

    for (int x = 0; x < nFieldWidth; ++x)
    {
        for (int y = 0; y < nFieldHeight; ++y)
        {
            int idx = pField[y * nFieldWidth + x];
            screen[(y + offset) * nScreenWidth + (x + offset)] = static_cast<int>(key[idx]);
        }
    }
}

void drawPiece(int idx)
{
    for (int pX = 0; pX < 4; ++pX)
    {
        for (int pY = 0; pY < 4; ++pY)
        {
            int pI = rotate(pX, pY, nCurrentRotation);

            if (tetromino[idx][pI] == 'X')
            {
                int pS = (pY + nCurrentY + offset) * nScreenWidth + (pX + nCurrentX + offset);
                screen[pS] = nCurrentPiece + 'A';
            }
        }
    }
}

void drawScreen()
{
    for (int y = 0; y < nScreenHeight; ++y)
    {
        for (int x = 0; x < nScreenWidth; ++x)
        {
            int pS = y * nScreenWidth + x;

            std::cout << static_cast<char>(screen[pS]);
        }
        std::cout << std::endl;
    }
}

void draw()
{
    std::system("clear");

    // draw field
    drawField();

    // draw current piece
    drawPiece(nCurrentPiece);

    // draw screen
    drawScreen();
}

void input()
{
    inputKey = getch();

    switch (inputKey)
    {
        // Right
        case 67:
            dir = Direction::RIGHT;
            break;
        // Left    
        case 68:
            dir = Direction::LEFT;
            break;
        // Down
        case 66:
            dir = Direction::DOWN;
            break;
        // Rotate
        case 'z':
           dir = Direction::ROTATE;
            break;
        case 'q':
            bGameOver = true;
        default:
            dir = Direction::UNDEFINED;
            break;
    }
}

void logic()
{
    if (dir == Direction::LEFT)    
    {
        nCurrentX -= 1;
    }

    if (dir == Direction::RIGHT)
    {
        nCurrentX += 1;
    }

    if (dir == Direction::DOWN)
    {
        nCurrentY += 1;
    }
}

int main()
{
    setup();

    while (!bGameOver)
    {
        draw();
        input();
        logic();
    }

    std::cout << "Exit!" << std::endl;
    
    return 0;
}
