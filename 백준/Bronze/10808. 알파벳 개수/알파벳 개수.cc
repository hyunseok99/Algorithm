#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
	string str;
	vector<char>v(27);
	vector<int>idx(26);
	fill(idx.begin(), idx.end(), 0);
	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < 26; j++) {
			v[j] = 'a' + j;
			if (str[i] == v[j])
				idx[j]++;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << idx[i] << " ";
	}
	return 0;
}
