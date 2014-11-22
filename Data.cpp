//class Data
#include "cvt.cpp"


class Data{
	public:
		Data(){
			key = 0;
			next = NULL;
		}
		Data(string w, string m){
			key = cvt(w);
			word = w;
			mean = m;
			next = NULL;
		}
		~Data(){}
		long key;
		string word;
		string mean;
		Data * next;
};
