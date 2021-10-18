#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

#pragma comment(lib, "winmm.lib")
//

//���� ����
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

//Ŀ��, ��ǥ�̵�
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//�ؽ�Ʈ, ��� ���� SET
void setColor(int color, int bgcolor)
{
    color &= 0xf;
    bgcolor &= 0xf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        (bgcolor << 4) | color);
}
//��Ʈ ���� SET
void setFontColor(int color)
{
    CONSOLE_SCREEN_BUFFER_INFO buff;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        (buff.wAttributes & 0xf0) | (color & 0xf));
}
//��� ���� SET
void setBgColor(int bgcolor) {
    CONSOLE_SCREEN_BUFFER_INFO buff;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        ((bgcolor & 0xf) << 4) | (buff.wAttributes & 0xf));
}
//�ؽ�Ʈ ���� GET
int getFontColor() {
    CONSOLE_SCREEN_BUFFER_INFO buff;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
    return buff.wAttributes & 0xf;
}
//��� ���� GET
int getBgColor() {
    CONSOLE_SCREEN_BUFFER_INFO buff;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
    return (buff.wAttributes & 0xf0) >> 4;
}

// Ŀ�� ������ ����
void CursorView(bool visible = false)
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
    cursorInfo.bVisible = visible; //Ŀ�� Visible TRUE(����) FALSE(����)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void drawMap() { // �� ������
    
}

int main() {
    string getKey;
    bool getKeyDown[5] = { false, false, false, false, false };
    CursorView();
    drawMap();
    //PlaySound(TEXT("mu.wav"), NULL, SND_FILENAME | SND_ASYNC); // ���� Ʈ�°�
    while (true)
    {
        if (_kbhit()) // Ű�Է� �ޱ�
        {
            getKey = _getch(); // String Ÿ������ �Է¹��� Ű�� ������ �ִ´�.
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
                if (getKeyDown[i]) cout << getKey + " �Է¹���" << endl;
        }

        for (int i = 0; i < 5; i++)
            if (getKeyDown[i]) getKeyDown[i] = false;

    }
}