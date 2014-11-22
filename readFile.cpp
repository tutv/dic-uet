//
const int sizeLine = 100;

#include "tool.cpp"

void readFile(){
	ifstream readFile("Data.txt");
	char dong[sizeLine];
	string word;
	string mean;
	while (!readFile.eof()){
		readFile.getline(dong,sizeLine);
		word = strtok(dong, ";");
		mean = strtok(NULL,";");
		Data* data = new Data(word,mean);
		insert(data);
	}
	readFile.close();
}

void writeFile(Data * data){
//	Data* result = find(data);
//	if (result!=NULL) return;
	ofstream writeFile("Data.txt",ios::out|ios::app);
	writeFile << endl << data->word << ";" << data->mean;// << endl;
	writeFile.close();
}