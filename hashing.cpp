const long Size = 19;

long cvt(std::string x) {
	long temp = 0;
	for (int i=x.length()-1; i>=0; i--) {
		int num = (int)(x.at(i) - 96);
		temp += (long)(num * pow(25, i));
	}
	return temp;
}

long hash(long key) {
	return key % Size;
}