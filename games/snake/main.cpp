#include <iostream>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <queue>
#include <utility>

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

bool gameOver;
bool ateFruit;

const int width = 20;
const int height = 20;

int xOffset = 2;

std::pair<int, int> head;
std::pair<int, int> fruit;

int score;
char dirChar;

std::deque<std::pair<int, int>> tail;

enum class Direction {STOP, LEFT, RIGHT, UP, DOWN};
Direction dir;

void setup()
{
    /* initialize random seed: */
    srand (time(NULL));
    
    dir = Direction::STOP;
    dirChar = ' ';
    
    gameOver = false;
    ateFruit = false;
    score = 0;
    
    head.first = width / 2 + xOffset;
    head.second = width / 2;
    
    fruit.first = rand() % width + xOffset;
    fruit.second = rand() % height;
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
                if (row == head.second && col == head.first)
                {
                    std::cout << "O";
                }
                else if (row == fruit.second && col == fruit.first)
                {
                    std::cout << "F";
                }
                else
                {
                    bool printTail = false;
                    for (const auto& coord : tail)
                    {
                        if (col == coord.first && row == coord.second)
                        {
                            std::cout << "o";
                            printTail = true;
                        }
                    }
                    
                    if (!printTail)
                    {   
                        std::cout << " ";
                    }
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
    
    std::cout << "fruitX: " << fruit.first - xOffset << ", fruitY: " << fruit.second << std::endl;
    std::cout << "score: " << score << std::endl;
    std::cout << "X: " << head.first - xOffset << "\nY: " << head.second << std::endl;
    std::cout << "direction char: " << dirChar << std::endl;
    //std::cout << "direction value: " << static_cast<std::underlying_type<Direction>::type>(dir) << std::endl;
    
    for (const auto& item : tail)
    {
        std::cout << item.first - xOffset << '\t' << item.second << std::endl;
    }
    
}

void input()
{
    dirChar = getch();
    
    switch(dirChar)
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
            dir = Direction::STOP;
            break;
    }
}

void logic()
{
    if (dir == Direction::STOP)
    {
        return;
    }

    if (ateFruit)
    {
        tail.push_back(head);
        ateFruit = false;
    }
    
    if (!tail.empty())
    {
        tail.pop_back();
        tail.push_front(head);
    }

    switch (dir)
    {
        case Direction::LEFT:
            --head.first;
            break;
        case Direction::RIGHT:
            ++head.first;
            break;
        case Direction::UP:
            --head.second;
            break;
        case Direction::DOWN:
            ++head.second;
            break;
        default:
            break;
    }
    
    /*if (head.first == 1 || head.first == width + 2 || head.second == -1 || head.second == height)
    {
        gameOver = true;
    } 
    */

    if (head.first == 1)
    {
        head.first = width + 1;
    }
    else if (head.first == width + 2)
    {
        head.first = 2;
    }

    if (head.second == -1)
    {
        head.second = height - 1;
    }
    else if (head.second == height)
    {
        head.second = 0;
    }
    
    for (const auto& coord : tail)
    {
        if (head.first == coord.first && head.second == coord.second)
        {
            gameOver = true;
            std::cout << "::::::";
            break;
        }
    }
    
    if (head.first == fruit.first && head.second == fruit.second)
    {
        ateFruit = true;
        score += 10;
        fruit.first  = rand() % width + xOffset;
        fruit.second = rand() % height;
    }
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
