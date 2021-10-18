#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

#pragma comment(lib, "winmm.lib")
//

//색깔 모음
enum ConsoleColor {
    CC_BLACK = 0,
    CC_DARKBLUE,
    CC_DARKGREEN,
    CC_DARKCYAN,
    CC_DARKRED,
    CC_DARKMAGENTA,
    CC_DARKYELLOW,
    CC_GRAY,
    CC_DARKGRAY,
    CC_BLUE,
    CC_GREEN,
    CC_CYAN,
    CC_RED,
    CC_MAGENTA,
    CC_YELLOW,
    CC_WHITE,
    CC_LIGHTGRAY = 7,
    CC_ORIGINAL = 7,
    CC_ORIGINALFONT = 7,
    CC_ORIGINALBG = 0
};

//커서, 좌표이동
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//텍스트, 배경 색상 SET
void setColor(int color, int bgcolor)
{
    color &= 0xf;
    bgcolor &= 0xf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        (bgcolor << 4) | color);
}
//폰트 색상 SET
void setFontColor(int color)
{
    CONSOLE_SCREEN_BUFFER_INFO buff;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        (buff.wAttributes & 0xf0) | (color & 0xf));
}
//배경 색상 SET
void setBgColor(int bgcolor) {
    CONSOLE_SCREEN_BUFFER_INFO buff;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        ((bgcolor & 0xf) << 4) | (buff.wAttributes & 0xf));
}
//텍스트 색상 GET
int getFontColor() {
    CONSOLE_SCREEN_BUFFER_INFO buff;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
    return buff.wAttributes & 0xf;
}
//배경 색상 GET
int getBgColor() {
    CONSOLE_SCREEN_BUFFER_INFO buff;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
    return (buff.wAttributes & 0xf0) >> 4;
}

// 커서 깜빡임 방지
void CursorView(bool visible = false)
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = visible; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void drawMap() { // 맵 디자인
    
}

int main() {
    string getKey;
    bool getKeyDown[5] = { false, false, false, false, false };
    CursorView();
    drawMap();
    //PlaySound(TEXT("mu.wav"), NULL, SND_FILENAME | SND_ASYNC); // 음악 트는거
    while (true)
    {
        if (_kbhit()) // 키입력 받기
        {
            getKey = _getch(); // String 타입으로 입력받은 키를 변수에 넣는다.
            if (getKey == "a") {
                getKeyDown[0] = true;
            }
            else if (getKey == "s") {
                getKeyDown[1] = true;
            }
            else if (getKey == "d") {
                getKeyDown[2] = true;
            }
            else if (getKey == "f") {
                getKeyDown[3] = true;
            }
            else if (getKey == "g") {
                getKeyDown[4] = true;
            }
            for (int i = 0; i < 5; i++)
                if (getKeyDown[i]) cout << getKey + " 입력받음" << endl;
        }

        for (int i = 0; i < 5; i++)
            if (getKeyDown[i]) getKeyDown[i] = false;

    }
}