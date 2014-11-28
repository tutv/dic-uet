#include "Data.h"
#include "Menu.h"
#include "Dictionary.h"

int main() {
	Dictionary dic = Dictionary();
	char fileName[20] = "Data.txt";
	dic.loadFile(fileName);
	
	Menu menu;
    int choose;
    gotoxy(1,1);	cout << "Tu dien ANH - VIET:";						//Ghi ten
    int line = 0; 														//Vi tri dong cua menu
    bool thoat = false;
    menu.printMenu();
    gotoxy(0, line+5);		cout << (char) 1; 							//Ve con tro toi menu
    while (!thoat) {
        if (kbhit()) {													//Neu Ban phim duoc nhan
            choose = move();
            gotoxy(0, line+5);		cout << " "; 						//Xoa con tro o vi tri cu~
            switch (choose) {
                case 1:													//1,3: Xuong
                case 3:{
                    line++;
                    if (line >= menu.numberOfItem()) line = 0;
                    break;
                }
                case 2:													//2,4: Len
                case 4:{
                    line--;
                    if (line < 0) line = menu.numberOfItem() - 1;
                    break;
                }
                case 5:{												//5: Enter
                	menu.deleteScreen();
                	string s;
                	gotoxy(5,5);
                	fflush(stdin);													//Xoa bo nho dem
                	switch(line){
                		case 0:{													//Tim kiem tu
                			cout << "Nhap tu can tim: ";	cin >> s;
                			Data * result = dic.find(s);
                			gotoxy(5,7);
                			if (result!=NULL){
                				cout << s << " --> " << result->mean;
                			}
							else	cout << "Khong tim thay \"" << s << "\"";
                			break;
                		}
                		case 1:{													//Them tu
                			cout << "Tu Tieng Anh muon them: ";		cin >> s;
                			char mean[50];
                			fflush(stdin);											//Xoa bo nho dem
                			gotoxy(5,7);	cout << "Nghia cua tu do: ";	gets(mean);
                			//Data * wordIn = new Data(s,mean);
                			dic.insert(new Data(s,mean));
							dic.updateFile(fileName);
							gotoxy(5,9);	cout << "Da them \"" << s << "\" vao tu dien!";
                			break;
                		}
                		case 2:{													//Xoa tu
                			cout << "Nhap tu can xoa: ";	cin >> s;
                			bool del = dic.remove(s);
                			gotoxy(5,7);
							if (del) cout << "Xoa \"" << s << "\" thanh cong!";
							else cout << "Khong the xoa \"" << s << "\"";
							dic.updateFile(fileName);
                			break;
                		}
                		case 3:{													//Thoat
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
            gotoxy(0, line+5);	cout << (char) 1;							//In con tro Menu
        }
    }
    menu.deleteScreen();
    gotoxy(8,5);	cout << "GOOD BYE!!!\n\n\n";	Sleep(500);
	return 0;
}
