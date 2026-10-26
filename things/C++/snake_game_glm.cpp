#include <windows.h>
#include <vector>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// 游戏配置
const int WIDTH = 40;
const int HEIGHT = 20;
const int INITIAL_SPEED = 200; // 毫秒

// 方向枚举
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

// 蛇的结构体
struct Snake {
    vector<pair<int, int>> body;
    Direction direction;
    bool grow;
};

// 游戏状态
Snake snake;
int score = 0;
int foodX, foodY;
int speed = INITIAL_SPEED;
bool gameRunning = false;

// 随机食物位置
void generateFood() {
    foodX = rand() % (WIDTH - 2) + 1;
    foodY = rand() % (HEIGHT - 2) + 1;

    // 确保食物不会生成在蛇身上
    for (const auto& segment : snake.body) {
        if (segment.first == foodX && segment.second == foodY) {
            generateFood();
            return;
        }
    }
}

// 初始化游戏
void initGame() {
    snake.body.clear();
    snake.body.push_back({WIDTH / 2, HEIGHT / 2});
    snake.body.push_back({WIDTH / 2, HEIGHT / 2 + 1});
    snake.body.push_back({WIDTH / 2, HEIGHT / 2 + 2});
    snake.direction = RIGHT;
    snake.grow = false;
    score = 0;
    speed = INITIAL_SPEED;

    generateFood();
    gameRunning = true;
}

// 绘制游戏界面
void draw() {
    // 清屏
    system("cls");

    // 绘制顶部信息
    cout << "========================================" << endl;
    cout << "        贪吃蛇游戏 (方向键控制)" << endl;
    cout << "========================================" << endl;
    cout << "分数: " << score << "  速度: " << (1000 / speed) << endl;
    cout << "========================================" << endl;

    // 绘制游戏区域
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            bool isSnake = false;
            bool isFood = false;

            // 检查是否是蛇
            for (const auto& segment : snake.body) {
                if (segment.first == x && segment.second == y) {
                    isSnake = true;
                    break;
                }
            }

            // 检查是否是食物
            if (x == foodX && y == foodY) {
                isFood = true;
            }

            // 绘制
            if (isFood) {
                cout << "●"; // 食物
            } else if (isSnake) {
                // 蛇头用不同的颜色
                if (x == snake.body[0].first && y == snake.body[0].second) {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12); // 红色
                    cout << "■";
                    SetConsoleTextAttribute(hConsole, 7); // 恢复默认
                } else {
                    cout << "■";
                }
            } else if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1) {
                cout << "│"; // 边界
            } else {
                cout << " "; // 空格
            }
        }
        cout << endl;
    }

    cout << "========================================" << endl;
    cout << "按方向键移动，ESC退出游戏" << endl;
}

// 移动蛇
void moveSnake() {
    if (!gameRunning || snake.direction == STOP) return;

    int headX = snake.body[0].first;
    int headY = snake.body[0].second;

    // 计算新蛇头位置
    switch (snake.direction) {
        case LEFT: headX--; break;
        case RIGHT: headX++; break;
        case UP: headY--; break;
        case DOWN: headY++; break;
    }

    // 检查碰撞（墙壁）
    if (headX <= 0 || headX >= WIDTH - 1 || headY <= 0 || headY >= HEIGHT - 1) {
        gameRunning = false;
        return; // 游戏结束
    }

    // 检查碰撞（自身）
    for (const auto& segment : snake.body) {
        if (headX == segment.first && headY == segment.second) {
            gameRunning = false;
            return; // 游戏结束
        }
    }

    // 添加新蛇头
    snake.body.insert(snake.body.begin(), {headX, headY});

    // 检查是否吃到食物
    if (headX == foodX && headY == foodY) {
        score += 10;
        snake.grow = true;
        generateFood();

        // 增加速度
        if (speed > 50) {
            speed -= 5;
        }
    } else {
        // 没吃到食物，移除蛇尾
        if (!snake.grow) {
            snake.body.pop_back();
        }
    }
}

// 处理键盘输入
void handleInput() {
    if (_kbhit()) {
        char key = _getch();

        switch (key) {
            case 72: // 上
                if (snake.direction != DOWN) snake.direction = UP;
                break;
            case 80: // 下
                if (snake.direction != UP) snake.direction = DOWN;
                break;
            case 75: // 左
                if (snake.direction != RIGHT) snake.direction = LEFT;
                break;
            case 77: // 右
                if (snake.direction != LEFT) snake.direction = RIGHT;
                break;
            case 27: // ESC
                gameRunning = false;
                break;
        }
    }
}

// 游戏主循环
void gameLoop() {
    initGame();

    while (gameRunning) {
        draw();
        handleInput();
        moveSnake();

        // 短暂延迟，避免刷新过快
        Sleep(speed);
    }

    // 游戏结束
    system("cls");
    cout << "========================================" << endl;
    cout << "        游戏结束!" << endl;
    cout << "========================================" << endl;
    cout << "最终分数: " << score << endl;
    cout << "========================================" << endl;
}

int main() {
    // 设置随机数种子
    srand((unsigned)time(NULL));

    // 设置控制台颜色
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);

    // 显示欢迎信息
    cout << "========================================" << endl;
    cout << "        贪吃蛇游戏" << endl;
    cout << "========================================" << endl;
    cout << "使用方向键控制蛇的移动" << endl;
    cout << "按ESC键退出游戏" << endl;
    cout << "========================================" << endl;
    cout << "按任意键开始游戏..." << endl;

    // 等待用户按键
    while (!_kbhit()) {
        Sleep(100);
    }
    _getch();

    system("cls");

    // 开始游戏
    gameLoop();

    cout << "按任意键退出..." << endl;
    while (!_kbhit()) {
        Sleep(100);
    }
    _getch();

    return 0;
}
