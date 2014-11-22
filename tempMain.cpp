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

	// cout << "dsjfljsd";
	Data * d = new Data("lovea", "thich hon");
	insert(d);
	int count = 0;
	for (int i=0; i<SIZE; i++){
		if (dic[i]->key!=0) {
			cout << i << "\t" << dic[i]->key << "\t\t" << dic[i]->word << " -->> " << dic[i]->mean << endl;
			count++;
		}

		Data * p = dic[i]->next;
		while (p!=NULL) {
			count++;
			cout << "ok";
			cout << i << "\t" << p->key << "\t\t" << p->word << " -->> " << p->mean << endl;
			p = p->next;
		}
	}
	cout << count << endl;
	return 0;
}
