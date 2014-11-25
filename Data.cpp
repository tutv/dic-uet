//class Data
#include "hashing.cpp"

class Data{
	public:
		Data(){
			key = 0;
			next = NULL;
		}
		Data(std::string w, std::string m){
			key = cvt(w);
			word = w;
			mean = m;
			next = NULL;
		}
		~Data(){}
		long key;
		std::string word;
		std::string mean;
		Data * next;
};
