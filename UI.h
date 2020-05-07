#pragma once
#include<iostream>
#include<Windows.h>
#include<time.h>
#include<string>
#include<conio.h>
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