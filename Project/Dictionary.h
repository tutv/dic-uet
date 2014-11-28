//Dictionary.h

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <fstream>
#include <cstring>

#include "Data.h"
#include "Menu.h"

const int sizeLine = 100;					//Lay toi da 100 ki tu moi dong trong File

class Dictionary {
	public:
		Dictionary();
		~Dictionary();
	
		//Dictionary --> <dic>
		void insert(Data *);				//Chen du lieu vao Bang Dictionnary
		Data * find(string);				//Tim tu trong Dictionary
		bool remove(string);				//Xoa tu trong Dictionary
		void print();						//In ra tat ca cac tu trong Dictionary
	
		//File
		void loadFile(char *);				//Doc File roi luu vao Dictionay
		void insert2File(Data *, char *);	//Maybe will delete
		bool updateFile(char *);			//Viet tat ca cac tu trong Dictionary ra File
	
	private:
		Data * dic[Size];					//Bang bam chua Dictionary
};
#endif
