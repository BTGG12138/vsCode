#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Dir { UP, RIGHT, DOWN, LEFT };

struct Node {
    int x, y;
};

const int W = 40;
const int H = 20;
Node snake[200];
int len = 3;
Dir dir = RIGHT;
int foodX, foodY;
bool gameOver = false;

// 隐藏光标，消除闪烁
void hideCursor() {
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 1;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

// 定位控制台光标
void gotoxy(int x, int y) {
    COORD pos = {SHORT(x), SHORT(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void createFood() {
    bool ok;
    do {
        ok = true;
        foodX = rand() % W;
        foodY = rand() % H;
        for (int i = 0; i < len; i++) {
            if (snake[i].x == foodX && snake[i].y == foodY) {
                ok = false;
                break;
            }
        }
    } while (!ok);
}

void turnLeft() {
    if(dir == UP)    dir = LEFT;
    else if(dir == RIGHT) dir = UP;
    else if(dir == DOWN)  dir = RIGHT;
    else if(dir == LEFT)  dir = DOWN;
}
void turnRight() {
    if(dir == UP)    dir = RIGHT;
    else if(dir == RIGHT) dir = DOWN;
    else if(dir == DOWN)  dir = LEFT;
    else if(dir == LEFT)  dir = UP;
}

void updateSnake() {
    // 身体跟随
    for(int i = len - 1; i > 0; i--)
        snake[i] = snake[i-1];

    // 头部前进
    switch(dir) {
        case UP:    snake[0].y--; break;
        case RIGHT: snake[0].x++; break;
        case DOWN:  snake[0].y++; break;
        case LEFT:  snake[0].x--; break;
    }

    // 撞墙
    if(snake[0].x < 0 || snake[0].x >= W || snake[0].y < 0 || snake[0].y >= H)
        gameOver = true;

    // 撞自身
    for(int i = 1; i < len; i++) {
        if(snake[0].x == snake[i].x && snake[0].y == foodY)
            gameOver = true;
    }

    // 吃到食物
    if(snake[0].x == foodX && snake[0].y == foodY) {
        len++;
        createFood();
    }
}

void draw() {
    gotoxy(0,0);
    // 顶边框
    for(int i=0;i<W+2;i++) cout << "#";
    cout << endl;

    for(int y=0;y<H;y++) {
        cout << "#";
        for(int x=0;x<W;x++) {
            bool isSnake = false;
            for(int i=0;i<len;i++) {
                if(snake[i].x == x && snake[i].y == y) {
                    cout << "O";
                    isSnake = true;
                    break;
                }
            }
            if(!isSnake) {
                if(x == foodX && y == foodY)
                    cout << "@";
                else
                    cout << " ";
            }
        }
        cout << "#\n";
    }
    // 底边框
    for(int i=0;i<W+2;i++) cout << "#";
    cout << "\nA左转 D右转 | ESC退出";
}

int main() {
    hideCursor();
    srand((unsigned)time(NULL));

    // 初始化蛇
    snake[0] = {5,5};
    snake[1] = {4,5};
    snake[2] = {3,5};
    createFood();

    while(!gameOver) {
        if(_kbhit()) {
            char k = _getch();
            if(k == 'a' || k == 'A') turnLeft();
            if(k == 'd' || k == 'D') turnRight();
            if(k == 27) break; // ESC
        }
        updateSnake();
        draw();
        Sleep(100); // 速度，越小越快
    }
    gotoxy(0, H+3);
    cout << "\nGame Over!" << endl;
    system("pause");
    return 0;
}