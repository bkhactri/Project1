#pragma once
#include"QInt.h"
#include"QFloat.h"
#include<fstream>
#include<time.h>
#include<Windows.h>
using namespace std;

// dich vi tri con tro
void gotoxy(int column, int line);
// text Color
void setColor(int color);
// ẩn con trỏ console
void Nocursortype();
// di chuyển
int Move();
// tạo khung lớn
void BigFrame();
// tạo 2 khung nhỏ bên trong
void Frame_1();
// tạo 1 khung nhỏ bên trong
void Frame_2();
// tạo 2 khung nhỏ bên trong dành cho Qfloat Dec
void Frame_3();
// tạo 1 khung nhỏ bên trong file
void Frame_4();
// tạo 2 khung nhỏ bên trong Shift
void Frame_5();
// tạo 2 khung nhỏ bên trong Shift Dec
void Frame_6();
// xoá vị trí nhập vào
void deleteInput();
// xóa vị trí xuất ra
void deleteOutPut();
// xóa menu
void deleteMenu();
// xuất kết quả
void OutPut(string s, string q, string p);
// kiểm tra enter, esc
void checkEnter();
// kiểm tra nhập thập phân
int checkDec(string s);
// kiểm tra nhập nhị phân
int checkBin(string s);
// kiểm tra nhập thập lục phân
int checkHex(string s);
// kiểm tra chia
int checkDiv(string s);
// kiểm tra QFloat thập phân
int checkQFloatDec(string s);
// xuất Invalid
void outputInvalidQInt();
// xuất Invalid QFloat
void outputInvalidQFloat();
// chuyển string sang int
int convertStringtoInt(string n);
// đọc file QInt
void ReadFileQInt(string input);
// đọc file QFloat
void ReadFileQFloat(string input);