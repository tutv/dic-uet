//#include "cvt.cpp"
#include "Data.cpp"
#include <fstream>

using namespace std;

const long SIZE = 19;

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
		Data * p = dic[hashKey];//->next;
		while (p->next!=NULL){
			p = p->next;
		}
		p->next = data;
	}
}

Data * find(string word){
	long key = cvt(word);
	long hashKey = hash(key);
	if (dic[hashKey]->key == key){
		return dic[hashKey];
	}
	else {
		Data* p = dic[hashKey];//->next;
		while(p->next!=NULL){
			p = p->next;
			if (p->key==key) return p;
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

				Data* p = dic[i];
				while (p->next != NULL) {
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

/*
bool removeF(string word) {
	Data * result = find(word);
	if (result == NULL) return false;
	else {
		
//		cout << "bat dau gan\n";
//		//Gan result=result->next, result tro toi result->next->next
//		result->key = result->next->key;
//		cout << "1\n";
//		result->word = result->next->word;
//		cout << "2\n";
//		result->mean = result->next->mean;
//		cout << "3\n";
//		result->next = result->next->next;
//		cout << "gan xong\n";
		
		//===============================================
		ofstream writeFile("Data.txt", ios::trunc|ios::out);
		for (int i=0; i<SIZE; i++) {
			if (dic[i]->key != 0) {
				if (result->key!=dic[i]->key)	writeFile << dic[i]->word << ";" << dic[i]->mean;
				Data* p = dic[i]->next;
				while (p!=NULL) {
					if (result->key!=p->key)	writeFile << endl << p->word << ";" << p->mean;
					p = p->next;
				}
			}
		}
		writeFile.close();
		result->key = 0;
		return true;
	}
}
*/
void printDic(){
	int count = 0;
	for (int i=0; i<SIZE; i++){
		if (dic[i]->key!=0) {
			cout << i << "\t" << dic[i]->key << "\t\t" << dic[i]->word << " -->> " << dic[i]->mean << endl;
			count++;
			Data * p = dic[i]->next;
			while (p!=NULL) {
				count++;
				cout << i << "\t" << p->key << "\t\t" << p->word << " -->> " << p->mean << endl;
				p = p->next;
			}
		}
		else cout << i << "\t" << "(_none_)" << endl;
	}
	cout << count << endl;
}
