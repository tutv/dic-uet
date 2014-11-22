//#include "cvt.cpp"
#include "Data.cpp"

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
