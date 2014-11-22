//#include "cvt.cpp"
#include "Data.cpp"
#include <fstream>

using namespace std;

const long SIZE = 67;

long hash(long key) {
	return key % SIZE;
}

Data * dic[SIZE];


void insert( Data * data) {
	long hashKey = hash(data->key);
	if (dic[hashKey]->key == 0) {
		dic[hashKey] = data;
	}
	else {
		Data * p = dic[hashKey]->next;
		while (p!=NULL){
			p = p->next;
		}
		p = data;
	}
}

Data * find(string word){
	long key = cvt(word);
	long hashKey = hash(key);
	if (dic[hashKey]->key == key){
		return dic[hashKey];
	}
	else {
		Data* p = dic[hashKey]->next;
		while(p!=NULL){
			if (p->key==key) return p;
			p = p->next;
		}
		return NULL;
	}
}

bool removeF(string word) {
	Data * result = find(word);
	if (result == NULL) return false;
	else {
		result->key = 0;
		ofstream writeFile("Data.txt", ios::trunc|ios::out);
		bool enter = false;
		for (int i=0; i<SIZE; i++) {
			if (dic[i]->key != 0) {
				// if (dic[i]->word != "love")
				if (enter) writeFile << endl;
				writeFile << dic[i]->word << ";" << dic[i]->mean;
				enter = true;

				Data* p = dic[i]->next;
				while (p!=NULL) {
					if (enter) writeFile << endl;
					writeFile << p->word << ";" << p->mean;
					enter = true;
					p = p->next;
				}
			}
		}

		writeFile.close();
		return true;
	}
}