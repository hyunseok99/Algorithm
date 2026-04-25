#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
	string *myStr;
	string myPattern;
	int n;
	int index,endCount;
	cin >> n >> myPattern;
	myStr = new string[n];
	index = myPattern.find("*");
	endCount = myPattern.length() - index -1;
	for (int i = 0; i < n; i++) {
		cin >> myStr[i];
		if (myStr[i].size() < (myPattern.substr(0, index).size() + myPattern.substr(index + 1).size())) {
			cout << "NE" << endl;
		}
		else if (myStr[i].substr(0, index) == myPattern.substr(0, index) && myStr[i].substr(myStr[i].length() - (myPattern.length() - index -1), myStr[i].length()) == myPattern.substr(index+1)) {
			cout << "DA" << endl;
		}
		else cout << "NE" << endl;
	}
	
	return 0;

}