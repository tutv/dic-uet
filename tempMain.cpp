#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include "Dictionary.cpp"

using namespace std;

int main() {
	Dictionary av = Dictionary();
	av.loadFile("Data.txt");
	av.print();

	cout << "-------------------------------------\n";
	bool del = av.remove("bad");
	if (del) cout << "Xoa thanh cmn cong :]]]]]]\n";
	else cout << "Eo xoa duoc :[[\n";

	av.print();
	av.updateFile("Data.txt");

	cout << "-------------------------------------\n";

	Data * wordDic = new Data("dictionary", "Tu dien");

	av.insert(wordDic);
	av.updateFile("Data.txt");

	av.print();
	return 0;
}