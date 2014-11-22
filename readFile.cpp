//
const int sizeLine = 100;

#include "Data.cpp"
#include "tool.cpp"

void readFile(Data* dic[]){
	ifstream readFile("Data.txt");
	char dong[sizeLine];
	char *p;
	string stringKey;
	string word;
	string mean;
	long longKey;
	while (!readFile.eof()){
		readFile.getline(dong,sizeLine);
		p = strtok(dong, ";");
		stringKey = p;
		longKey = 0;
		for (int i=stringKey.size()-1; i>=0; i--){
			longKey += ((int)stringKey[i]-48)*pow(10,stringKey.size()-1-i);
		}
		word = strtok(NULL,";");
		mean = strtok(NULL,";");
		Data* data = new Data(longKey,word,mean);
		cout <<  longKey << word << mean;
		tool a;
		cout << "alsdlfnldgnlsdg";
		a.insert(dic,data);
		cout << ";sdajgflsdkg";
	}
	readFile.close();
}
