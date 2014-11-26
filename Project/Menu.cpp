//Menu.cpp

#include "Menu.h"

void gotoxy(int column, int line)											//Nhay con tro toi toa do (line,collum)  ->  Search tren mang
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
 
int move() {	//Bat su kien ban phim
    char c = getch();
    if ((int) c == -32) c = getch();
    switch ((int) c) {
        case 80:
            return 1; //Nut "Xuong"
        case 72:
            return 2; //Nut "Len"
        case 77:
            return 3; //Nut "Phai"
        case 75:
            return 4; //Nut "Trai"
        case 27:
            return 8; //Nut "ESC" thoat
        case 13:
            return 5; //Nut "Enter"
        default:
            return 0; //Ngoai le -> 0
    }
}
 
Menu::Menu() {
    item = new string[10];
    _numberOfItem = 4;
    item[0] = "Tim kiem tu";
    item[1] = "Them tu";
    item[2] = "Xoa tu";
    item[3] = "Thoat";
}
 
void Menu::printMenu() {
    for (int i = 0; i < _numberOfItem; i++) {
        gotoxy(3, i+5);	//+5: in xuong dong thu 5
        cout << item[i];
        Sleep(100); //Tam dung 100ms
    }
}
 
void Menu::deleteMenu() {
    for (int i = 0; i < _numberOfItem; i++) {
        Sleep(100);
        gotoxy(0, i+5);	//+5: in xuong dong thu 5
        for (int j = 0; j < item[i].size() + 3; j++) {
            cout << " "; //Xoa bang cach ghi de ki tu trang
        }
    }
}

void Menu::deleteScreen(){	//Chi xoa khu vuc co Menu
	for (int i = 0; i < 2*_numberOfItem; i++) {
        Sleep(50);
        gotoxy(0, i+5);	//+5: in xuong dong thu 5
        cout << "                                             "; //Xoa bang cach ghi de ki tu trang
    }
}

