#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <windows.h>
#include <cmath>

#include <conio.h>




using namespace std;

#include "menu.cpp"
#include "Dictionary.cpp"

int main() {
	
	Dictionary dic = Dictionary();
	dic.loadFile("Data.txt");
	
	Menu menu;
    int x;
    gotoxy(1,1);	cout << "Tu dien ANH - VIET:";
    int line = 0; //V? trí dòng c?a menu
    bool thoat = false; 
    menu.printMenu();
    gotoxy(0, line+5);	////+5: in xuong dong thu 5
    cout << (char) 1; //V? con tr? tr? t?i menu
    while (!thoat) {
        if (kbhit()) {
            x = move();
            gotoxy(0, line+5);	//+5: in xuong dong thu 5
            cout << " "; //Xóa con tr? ? v? trí cu
            switch (x) {
                case 1:
                case 3:{
                    line++;
                    if (line >= menu.numberOfItem()) line = 0;
                    break;
                }
                case 2:
                case 4:{
                    line--;
                    if (line < 0) line = menu.numberOfItem() - 1;
                    break;
                }
                case 5:{
                	menu.deleteMenu();
                	string s;
                	gotoxy(5,5);
                	switch(line){
                		case 0:{
                			
                				cout << "Nhap tu can tim: ";	cin >> s;
                			Data * result = dic.find(s);
                			gotoxy(5,6);
                			if (result!=NULL){
                				cout << s << " --> " << result->mean;
                			}
							else	cout << "Khong tim thay";
                			break;
                		}
                		case 1:{
                			//string s;
                			fflush(stdin);
                			cout << "Tu Tieng Anh muon them: ";		cin >> s;
                			//string mean;
                			char mean[50];
                			fflush(stdin);
                			gotoxy(5,7);	cout << "Nghia cua tu do: ";	gets(mean);//cin >> mean;
                			Data * wordIn = new Data(s,mean);
                			dic.insert(wordIn);
							dic.updateFile("Data.txt");
							gotoxy(5,8);	cout << "Da them \"" << s << "\"vao tu dien!";
                			break;
                		}
                		case 2:{
                			cout << "Nhap tu can xoa: ";	cin >> s;
                			bool del = dic.remove(s);
                			gotoxy(5,6);
							if (del) cout << "Xoa \"" << s << "\"thanh cong!";
							else cout << "Khong the xoa \"" << s << "\"";
							dic.updateFile("Data.txt");
                			break;
                		}
                		case 3:{
                			thoat = true;
                			break;
                		}
                	}

                	if (thoat) break;
                	getch();
                	menu.deleteScreen();
                	menu.printMenu();
                    break;
                }
                case 8:
                    thoat = true;
            }
            gotoxy(0, line+5);	////+5: in xuong dong thu 5
            cout << (char) 1;
        }
    }
    menu.deleteMenu();

//	//Load file
//	Dictionary av = Dictionary();
//	av.loadFile("Data.txt");
//	av.print();
//	cout << "-------------------------------------\n";

//	//Remove Word
//	bool del = av.remove("bad");
//	if (del) cout << "Xoa thanh cmn cong :]]]]]]\n";
//	else cout << "Eo xoa duoc :[[\n";

//	av.print();
//	av.updateFile("Data.txt");
//	cout << "-------------------------------------\n";

//	//Insert Word
//	Data * wordDic = new Data("dictionary", "Tu dien");

//	av.insert(wordDic);
//	av.updateFile("Data.txt");

//	av.print();
//	cout << "-------------------------------------\n";

//	//Find Word
//	Data * findWord = av.find("love");
//	if (findWord) cout << "love  ------------>  " << findWord->mean << endl;
//	else cout << "Eo co tu day!!!" << endl;

	return 0;
}
