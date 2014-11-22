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
	Data * data= new Data("love","yeu say dam");
	readFile();
	Data* r = find("love");
	if (r==NULL){
		writeFile(data);
		insert(data);
	}

	for (int i=0; i<SIZE; i++){
		if (dic[i]->key!=0)
		cout << dic[i]->word << endl;
	}
	Data* result = find("fuck");
	if (result==NULL)cout << "deo co";
	else cout << endl << "nghia cua tu la: " << result->mean << endl;

	bool del = removeF("fuck");
	if (del) cout << "Done!";
	else cout << "False!";
	return 0;
}
