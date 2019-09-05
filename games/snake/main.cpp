#include <iostream>
#include <time.h>
#include <unistd.h>
#include <termios.h>

char getch();

bool gameOver;
const int width = 20;
const int height = 20;
int xOffset = 2;
int x, y; // snake head coordinates
int fruitX, fruitY;
int score;

enum class Direction {STOP, LEFT, RIGHT, UP, DOWN};
Direction dir;

void setup()
{
    /* initialize random seed: */
    srand (time(NULL));
    
    dir = Direction::STOP;
    gameOver = false;
    score = 0;
    x = width / 2 + xOffset;
    y = width / 2;
    fruitX = rand() % width + xOffset;
    fruitY = rand() % height;
    
    std::system("clear");
    std::cout << "fruitX: " << fruitX << ", fruitY: " << fruitY << std::endl;
 }

void draw()
{
    std::system("clear");
    
    std::cout << "  01234567890123456789 " << std::endl;
    std::cout << "  ";
    for (int col = 0; col < width; ++col)
    {
        std::cout << "#";
    }
    
    std::cout << std::endl;
    
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width + 3; ++col)
        {
            if (col == 0)
            {
                std::cout << row % 10;
            }
            else if (col == 1 || col == width + 2)
            {
                std::cout << "#";
            }
            else
            {
                if (row == y && col == x)
                {
                    std::cout << "O";
                }
                else if (row == fruitY && col == fruitX)
                {
                    std::cout << "F";
                }
                else
                {
                    std::cout << " ";
                }
            }            
        }    
        std::cout << std::endl;
    }
    
    std::cout << "  ";
    for (int col = 0; col < width; ++col)
    {
        std::cout << "#";
    }
    
    std::cout << std::endl;
    
    std::cout << "X: " << x - xOffset << "\nY: " << y<< std::endl;
    std::cout << "score: " << score << std::endl;
}

void input()
{
    switch(getch())
    {
        case 'a':
            dir = Direction::LEFT;
            break;
        case 'd':
            dir = Direction::RIGHT;
            break;
        case 'w':
            dir = Direction::UP;
            break;
        case 's':
            dir = Direction::DOWN;
            break;
        case 'x':
            gameOver = true;
            break;          
        default:
            break;
    }
}

void logic()
{
    switch (dir)
    {
        case Direction::LEFT:
            --x;
            break;
        case Direction::RIGHT:
            ++x;
            break;
        case Direction::UP:
            --y;
            break;
        case Direction::DOWN:
            ++y;
            break;
        default:
            break;
    }
    
    if (x == 1 || x == width + 2 || y == -1 || y == height)
    {
        gameOver = true;
    } 

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
} 

char getch() {
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

int main()
{
    setup();
    
    while (!gameOver)
    {
        draw();
        input();
        logic();
    }
	
    std::cout << "Game over!" << std::endl;
    
    getchar();
	return 0;
}
