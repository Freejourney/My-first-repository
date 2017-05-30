#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <windows.h>

#define IND_UP 0
#define IND_DOWN 1

using namespace std;

HANDLE h_std_out = GetStdHandle(STD_OUTPUT_HANDLE);	//不能直接使用STD_OUTPUT_HANDLE,而要获取它的句柄

int cur_indicator = 0;
int MENU_X = 50, MENU_Y = 13;
void setColor(unsigned int color);
void cursorPos(short x, short y);
void drawPoint(int pos_x, int pos_y, string str);
void drawLOGO();
void drawMENU();
void drawINFO();
void InitUI();

void UI_loop();
void drawINDICATOR(int indicator);

void beginGame() { cout << "BeginGame() " << endl; }
void continueGame() { cout << "ContinueGame() " << endl; }
void showStrategy() { cout << "ShowStrategy() " << endl; }
void exitGame() { cout << "exitGame() " << endl; }

int main()
{
	InitUI();
	UI_loop();

	return 0;
}

void setColor(unsigned int color)
{
	SetConsoleTextAttribute(h_std_out, FOREGROUND_INTENSITY | color);
}

void InitUI()
{
	system("cls");
	system("mode con cols=110 lines=30");
	for(int i = 0; i < 20; i++)
		cout << endl;
	
	setColor(FOREGROUND_RED);
	drawLOGO();
	
	setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	drawMENU();
	
	setColor(FOREGROUND_GREEN);
	drawINFO();
	
	setColor(FOREGROUND_INTENSITY);
	drawPoint(MENU_X - 3, MENU_Y + cur_indicator , ">>>");
}

void drawLOGO()
{
	int LOGO_X = 30, LOGO_Y = 4;
	drawPoint(LOGO_X , LOGO_Y + 0, "       _                                           ");
	drawPoint(LOGO_X , LOGO_Y + 1, " _ __ | | __ _ _ __   ___  __      ____ _ _ __ ___ ");
	drawPoint(LOGO_X , LOGO_Y + 2, "| '_ \\| |/ _` | '_ \\ / _ \\ \\ \\ /\\ / / _` | '__/ __|");
	drawPoint(LOGO_X , LOGO_Y + 3, "| |_) | | (_| | | | |  __/  \\ V  V / (_| | |  \\__ \\");
	drawPoint(LOGO_X , LOGO_Y + 4, "| .__/|_|\\__,_|_| |_|\\___|   \\_/\\_/ \\__,_|_|  |___/");
	drawPoint(LOGO_X , LOGO_Y + 5, "|_|                                                ");
}

void drawMENU()
{
	drawPoint(MENU_X, MENU_Y + 0, " 开始游戏");
	drawPoint(MENU_X, MENU_Y + 2, " 继续游戏");
	drawPoint(MENU_X, MENU_Y + 4, " 游戏攻略");
	drawPoint(MENU_X, MENU_Y + 6, " 退出游戏");
}

void drawINFO()
{
	int INFO_X = 30, INFO_Y = 22;
	drawPoint(INFO_X + 20, INFO_Y + 0, "Version  1.0");
	drawPoint(INFO_X + 15, INFO_Y + 1, "All Right Reserved @ddw.");
}

void drawPoint(int pos_x, int pos_y, string str)
{
	cursorPos(pos_x, pos_y);
	cout << str;
}

void cursorPos(short x, short y)
{
	_COORD pos = {x, y};
	SetConsoleCursorPosition(h_std_out, pos);
	//SetConsoleCursorPosition(STD_OUTPUT_HANDLE, pos);	//不能直接使用STD_OUTPUT_HANDLE,而要获取它的句柄
}

void UI_loop()
{
	int ch;
	while(1)
	{
		switch(ch = _getch()) 
		{
			case 0xE0:
				switch(ch = _getch())
				{
					case 72: drawINDICATOR(IND_UP); break;
					case 80: drawINDICATOR(IND_DOWN); break;
					case 75:
					case 77:
					default: break;
				}
				break;
			case 13:
				switch(cur_indicator)
				{
					case 0: beginGame(); break;
					case 2: continueGame(); break;
					case 4: showStrategy(); break;
					case 6: exitGame(); break;
				}
				break;
		}
	}
}

void drawINDICATOR(int indicator)
{
	drawPoint(MENU_X - 3, MENU_Y + cur_indicator, "   ");
	switch(indicator)
	{
		case IND_UP: cur_indicator = (cur_indicator + 8 - 2) % 8; break;
		case IND_DOWN: cur_indicator = (cur_indicator + 8 + 2) % 8; break;	//套路 
		default: break;
	}
	drawPoint(MENU_X - 3, MENU_Y + cur_indicator, ">>>");
}
