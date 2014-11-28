//Data.cpp
#include "Data.h"

long cvt(string x) {
	long temp = 0;
	for (int i=x.length()-1; i>=0; i--) {
		if (!((x.at(i)>='A' && x.at(i)<='Z') || (x.at(i)>='a' && x.at(i)<='z')))	throw invalid_argument("Ban vua nhap ki tu khong phai la Chu cai!");
		int num = (int)(x.at(i) - 96);
		if (x.at(i)>='A' && x.at(i)<='Z')	num+=32;	//Neu la ki tu viet hoa thi chuyen ve viet thuong
		temp += (long)(num * pow(26, i));				//Chuyen sang he co so 26
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

Data::Data(string w, string m){
	key = cvt(w);
	word = w;
	mean = m;
	next = NULL;
}

Data::~Data(){
}
