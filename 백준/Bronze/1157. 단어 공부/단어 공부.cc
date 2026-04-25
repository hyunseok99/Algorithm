#include <iostream>
#include <string>
using namespace std;

int main() {
	string stc;
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int num[26] = { 0, };
	getline(cin, stc);
	int max = 0;
	int max_idx = 0;
	int count = 0;
	for (int i = 0; i < stc.length(); i++) {
		stc[i] = toupper(stc[i]);
		for (int j = 0; j < 26; j++) {
			if (stc[i] == alpha[j]) 
				num[j]++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (max < num[i]) {
			max = num[i];
			max_idx = i;
		}
	}
	for (int k = 0; k < 26; k++) {
		if (max == num[k])
			count++;
	}

	if (count > 1) cout << "?";
	else cout << alpha[max_idx];

	return 0;
}