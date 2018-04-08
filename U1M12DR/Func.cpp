#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//enum col { yellow = 14, white = 15, red = 12, green = 11}number;
//
//void color(col c)
//{
//	SetConsoleTextAttribute(hConsole, (int)c);
//}

void yellow()
{
	SetConsoleTextAttribute(hConsole, 14);
}

void white()
{
	SetConsoleTextAttribute(hConsole, 15);
}

void red()
{
	SetConsoleTextAttribute(hConsole, 12);
}

void green()
{
	SetConsoleTextAttribute(hConsole, 11);
}