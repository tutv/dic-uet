#include "cvt.cpp"

using namespace std;

const long SIZE = 7;

long hash(long key) {
	return key % SIZE;
}

Data * dic[SIZE] ;

class tool() {
	public:
		static void insert(Data * [], string, string);
		static void remove(Data * [], string);
		static int size();
		static bool isEmpty();
}

void tool::insert(Date * dic[], Data * data) {
	long hashKey = hash(data.key);
	if (dic[hashKey]->key == 0) {
		dic[hashKey] = data;
	}
	else {
		Data * p = dic[hashKey]->next;
		while (p->key != 0)
		p = p->next;

		p = data;
	}
}