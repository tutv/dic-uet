//Menu.cpp

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
 
int move() {
    char c = getch();
    if ((int) c == -32) c = getch();
    switch ((int) c) {
        case 80:
            return 1; //cout << "Xuong";
        case 72:
            return 2; //cout << "Len";
        case 77:
            return 3; //cout << "Phai";       
        case 75:
            return 4; //cout << "Trai";
        case 27:
            return 8; //Nut ESC thoat
        case 13:
            return 5; //Nut Enter
        default:
            return 0; //cout << "Sai";
    }
}
 
class Menu {
    public:
        Menu();
	    ~Menu() {}
	    void printMenu();
	    void deleteMenu(); //Xóa menu khi k?t thúc chuong trình b?ng cách vi?t dè kí t? tr?ng
	    void deleteScreen();
	    int numberOfItem() {
	        return _numberOfItem;
	    }
	    string * getItem() {
	        return item;
	    }
    private:
        string * item; //M?ng luu tên c?a các menu
    	int _numberOfItem; //S? lu?ng menu
};
 
Menu::Menu() {
    item = new string[100];
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
        Sleep(100); //T?m d?ng 100ms
    }
}
 
void Menu::deleteMenu() {
    for (int i = 0; i < _numberOfItem; i++) {
        Sleep(100);
        gotoxy(0, i+5);	//+5: in xuong dong thu 5
        for (int j = 0; j < item[i].size() + 3; j++) {
            cout << " "; //Xóa b?ng cách ghi dè kí t? tr?ng
        }
    }
}

void Menu::deleteScreen(){
	for (int i = 0; i < _numberOfItem; i++) {
        Sleep(100);
        gotoxy(0, i+5);	//+5: in xuong dong thu 5
        cout << "                                             "; //Xóa b?ng cách ghi dè kí t? tr?ng
    }
}
