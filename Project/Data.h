//Data.h

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <cmath>
using namespace std;

const long Size = 19;	//So phan tu trong Mang
long cvt(string);		//Chuyen mot xau thanh so
long hash(long);		//Chuyen mot so thanh toa do trong Bang? bam

class Data{
	public:
		Data();
		Data(string, string);
		~Data();
		long key;		//Ma cua Word sau khi cvt()
		string word;	//Tu tieng Anh
		string mean;	//Nghia cua Word
		Data * next;
};
#endif
