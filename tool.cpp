#include "cvt.cpp"

using namespace std;

const long SIZE = 7;

long hash(long key) {
	return key % SIZE;
}

Data * dic[SIZE] = new Data[SIZE];

class tool {
	public:
		static void insert(Data * [], Data*);
		static void remove(Data * [], string);
		static int size();
		static bool isEmpty();
};

void tool::insert(Data * dic[], Data * data) {
	long hashKey = hash(data->key);
	cout << "deoXong";
	if (dic[hashKey]->key == 0) {
		cout << "deoXong";
		dic[hashKey] = data;
		cout << "xong";
	}
	else {
		Data * p = dic[hashKey]->next;
		while (p->key != 0) p = p->next;
		cout << "else";
		p = data;
	}
}
