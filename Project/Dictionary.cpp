//Dictionary.cpp

#include "Dictionary.h"


Dictionary::Dictionary() {
	for (int i=0; i<Size; i++) {
		dic[i] = new Data();
	}
}

Dictionary::~Dictionary() {
}



void Dictionary::insert(Data * data) {
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

Data * Dictionary::find(string word){
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

bool Dictionary::remove(string word) {
	bool test = false;
	Data * result = find(word);
	if (result == NULL) test = false;
	else {
		long hashKey = hash(result->key);
		if (dic[hashKey]->key == result->key) {
			dic[hashKey]->key = dic[hashKey]->next->key;
			dic[hashKey]->word = dic[hashKey]->next->word;
			dic[hashKey]->mean = dic[hashKey]->next->mean;
			dic[hashKey]->next = dic[hashKey]->next->next;
		}
		else if (dic[hashKey]->key!=0){
			Data * p = dic[hashKey];
			while (p->next->key!=result->key && p->next!=NULL){
				p = p->next;
			}
			if (p->next->key==result->key){
				p->next = p->next->next;
				test = true;
			}
			if (p->next==NULL)	test = false;
		}
		test = true;
	}
	return test;
}

void Dictionary::print(){
	int count = 0;
	for (int i=0; i<Size; i++){
		if (dic[i]->key > 0) {
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

void Dictionary::loadFile(char * fileName){
	ifstream readFile(fileName);
	char dong[sizeLine];
	string word;
	string mean;
	while (!readFile.eof()){
		readFile.getline(dong,sizeLine);
		word = strtok(dong, ";");
		mean = strtok(NULL,";");
		Data* data = new Data(word,mean);
		insert(data);
	}
	readFile.close();
}

void Dictionary::insert2File(Data * data, char * fileName){
	ofstream writeFile(fileName, ios::out|ios::app);
	writeFile << endl << data->word << ";" << data->mean;// << endl;
	writeFile.close();
}

bool Dictionary::updateFile(char * fileName) {
	ofstream writeF(fileName, ios::trunc|ios::out);
	bool enter = false;
	for (int i=0; i<Size; i++) {
		if (dic[i]->key > 0) {
			if (enter) writeF << endl;
			writeF << dic[i]->word << ";" << dic[i]->mean;
			enter = true;

			Data* p = dic[i]->next;
			while (p != NULL) {
				writeF << endl << p->word << ";" << p->mean;
				p = p->next;
			}
		}
	}
	writeF.close();
}

