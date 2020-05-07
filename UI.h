#pragma once
#include<iostream>
#include<Windows.h>
#include<time.h>
#include<string>
#include<conio.h>
using namespace std;

void Nocursortype();
void gotoxy(int column, int line);
void setColor(int color);
int Move();
void BigFrame();
void Frame_1();
void Frame_2();
//void deleteFrame_1();
//void deleteFrame_2();
void deleteInput();
void deleteOutPut();
void deleteMenu();
void OutPut(string s, string q, string p);
//void OutPutInvalid(string nbit1,string nbit2);