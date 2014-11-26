//Menu.h

#ifndef MENU_H
#define MENU_H

#include <conio.h>
#include <windows.h>
#include <iostream>
using namespace std;

void gotoxy(int, int);			//Nhay toa do man hinh
int move();						//Bat su kien ban phim

class Menu {
    public:
        Menu();
	    ~Menu() {}
	    void printMenu();
	    void deleteMenu(); 		//Xoa menu sau khi da chon 1 mneu
	    void deleteScreen();	//Xoa man hinh
	    int numberOfItem() {
	        return _numberOfItem;
	    }
	    string * getItem() {
	        return item;
	    }
    private:
        string * item; 			//Mang luu ten cua cac menu
    	int _numberOfItem; 		//So luong menu
};

#endif
