#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;
#include "readFile.cpp"
//#include "Data.cpp"

int main()
{
	for (int i=0; i<SIZE; i++){
		dic[i] = new Data();
	}
	readFile();



//	if (find("lovea")!=NULL)cout << "Co lovea\n";
//	else cout << "Khong co lovea\n";

	Data* s = new Data("s","chu s trong bang chu cai");
	if (find(s->word)==NULL){
		writeFile(s);
		insert(s);
	}
	string xoa = "ask";
	if(removeF(xoa)) cout << "xoa thanh cmn cong\n";
	else cout << "eo xoa duoc/khong co tu " << xoa << " trong tu dien\n";

	printDic();
	return 0;
}
