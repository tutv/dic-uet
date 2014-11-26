//Data.cpp
#include "Data.h"

long cvt(string x) {
	long temp = 0;
	for (int i=x.length()-1; i>=0; i--) {
		int num = (int)(x.at(i) - 96);
		temp += (long)(num * pow(25, i));	//Chuyen sang he co so 25
	}
	return temp;
}

long hash(long key) {
	return key % Size;
}

//=================================================

Data::Data(){
	key = 0;
	next = NULL;
}

Data::Data(std::string w, std::string m){
	key = cvt(w);
	word = w;
	mean = m;
	next = NULL;
}

Data::~Data(){
}
