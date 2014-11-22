#include <iostream>
#include <cmath>
using namespace std;
long cvt(string x) {
	long temp = 0;
	for (int i=x.length()-1; i>=0; i--) {
		int num = (int)(x.at(i) - 96);
		temp += (long)(num * pow(25, i));
		// temp += num;
	}
	return temp;
}