#include <iostream>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <conio.h>
using namespace std;

void goToXY(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Hurdle {
    int x;
    int gapY;
};

class HurdleQueue {
public:
    static const int SIZE = 4;
    Hurdle arr[SIZE];
    int front, rear;
    int screenWidth, screenHeight, gap, spacing;

    HurdleQueue(int width, int height, int hGap) {
        screenWidth = width;
        screenHeight = height;
        gap = hGap;
        front = 0;
        rear = SIZE - 1;
        spacing = (screenWidth / SIZE) + 10;
        initializeQueue();
    }

    void initializeQueue() {
        for (int i = 0; i < SIZE; i++) {
            arr[i].x = spacing * (i + 1);
            arr[i].gapY = rand() % (screenHeight / 3) + gap;
        }
    }

    void updatePositions() {
        for (int i = 0; i < SIZE; i++) {
            arr[i].x--;

            if (arr[i].x == -1) {
                int prev = (i == 0) ? SIZE - 1 : i - 1;
                arr[i].x = arr[prev].x + spacing;
                arr[i].gapY = rand() % (screenHeight / 3) + gap;

                for (int j = 0; j < screenHeight; j++) {
                    goToXY(0, j);
                    cout << " ";
                }
            }
        }
    }
};

class Flappy_Bird {
    int screenWidth = 79;
    int screenHeight = 25;

    int birdX = 17;
    int birdY = 15;

    int jump = 4;
    int score = 0;
    int hurdleGap = 8;

    HurdleQueue hurdles;

public:
    Flappy_Bird() : hurdles(screenWidth, screenHeight, hurdleGap) {
        srand(time(NULL));
    }

    void printHurdles() {
        for (int i = 0; i < HurdleQueue::SIZE; i++) {
            int count = 0;

            for (int j = 0; j < screenHeight; j++) {
                if (hurdles.arr[i].gapY == j)
                    count = hurdleGap;

                if (count == 0) {
                    if (hurdles.arr[i].x < screenWidth) {
                        goToXY(hurdles.arr[i].x + 1, j);
                        cout << " ";
                        goToXY(hurdles.arr[i].x, j);
                        cout << i;
                    }
                }
                else {
                    if ((count == 1 || count == hurdleGap) && hurdles.arr[i].x < screenWidth) {
                        if (hurdles.arr[i].x + 1 > 0) {
                            goToXY(hurdles.arr[i].x + 1, j);
                            cout << "   ";
                        }
                        if (hurdles.arr[i].x - 1 > 0) {
                            goToXY(hurdles.arr[i].x - 1, j);
                            cout << "===";
                        }
                    }
                    count--;
                }
            }
        }

        hurdles.updatePositions();
    }

    void clearBird() {
        goToXY(birdX - 5, birdY);     cout << "   ";
        goToXY(birdX - 5, birdY + 1); cout << "      ";
        goToXY(birdX - 5, birdY + 2); cout << "       ";
    }

    void printBird() {
        goToXY(birdX - 5, birdY);        cout << " __";
        goToXY(birdX - 5, birdY + 1);    cout << "/-/o\\";
        goToXY(birdX - 5, birdY + 2);    cout << "\\_\\-/";
    }

    void printScore() {
        goToXY(0, screenHeight + 4);
        cout << "Score: " << score;
    }

    void printRoad() {
        for (int i = 0; i <= screenWidth; i++) {
            goToXY(i, screenHeight);      cout << "_";
            goToXY(i, screenHeight + 1);  cout << "/";
            goToXY(i, screenHeight + 2);  cout << "=";
        }
    }

    bool collisionCheck() {
        if (birdY == 0 || birdY + 3 == screenHeight)
            return true;

        for (int i = 0; i < HurdleQueue::SIZE; i++) {
            int hx = hurdles.arr[i].x;
            int gy = hurdles.arr[i].gapY;

            if (hx == birdX &&
                (birdY >= gy || birdY + 3 <= gy + hurdleGap)) {
                score++;
            }

            if (hx >= birdX - 5 && hx <= birdX &&
                (birdY <= gy || birdY + 3 >= gy + hurdleGap)) {
                return true;
            }
        }

        return false;
    }

    void play() {
        printRoad();

        while (true) {
            if (GetAsyncKeyState(VK_SPACE))
                birdY -= jump;

            printHurdles();
            printBird();
            printScore();

            if (collisionCheck()) break;

            Sleep(100);
            clearBird();
            birdY += 1;
        }
    }
};

int main() {

    while (true) {
        Flappy_Bird fb;
        fb.play();

        goToXY(30, 30);
        cout << "Do you want to play again? (Y/N)";

        char ch;
        cin >> ch;
        if (ch == 'N' || ch == 'n')
            break;

        system("cls");
    }

    return 0;
}
