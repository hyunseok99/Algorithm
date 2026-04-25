#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
bool error = false;
deque<string> d;

void R(deque<string>& d2) {
	reverse(d2.begin(), d2.end());
	// d=d2;
}

void D(deque<string>& d3) {
	d3.pop_front();
	//d = d3;
}


void ps(string str) { // [1,2,42] -> 1,2,42
	

	int prev = 1, current = str.find(',');
	while (current != string::npos) {
		string substring = str.substr(prev, current - prev);
		d.push_back(substring);
		prev = current + 1;
		current = str.find(',', prev);
	}
		d.push_back(str.substr(prev,str.size()-prev-1));
}




int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	int t; cin >> t;
	cin.ignore();
	for (int i = 0; i < t; i++) {
		string s, s2;  // s : RDDDR
		int n; // [1,2,3~~] 원소 개수
		getline(cin, s2);
		cin >> n;
		//if (n == 0) {
		//	error = true;
		//}
		cin.ignore();
		getline(cin, s);
		ps(s);
		bool isReverse = false;
		if (d.empty()) {
			error = true;
		}
		else {
			for (int j = 0; j < s2.size(); j++) {
				if (s2[j] == 'R') isReverse = !isReverse;
				else if (s2[j] == 'D') {
					if (n == 0) error = true;
					if (d.empty()) {
						error = true;
						break;
					}
					if (isReverse) d.pop_back();
					else d.pop_front();
				}
			}
		}

		if (error) {
			cout << "error" << '\n';
		}
		else {
			cout << '[';
			if (isReverse) {
				while (!d.empty()) {
					cout << d.back();
					d.pop_back();
					if (!d.empty()) cout << ',';
				}
			}
			else {
				while (!d.empty()) {
					cout << d.front();
					d.pop_front();
					if (!d.empty()) cout << ',';
				}
			}
			cout << "]\n";
		}
		error = false;
		isReverse = false;
		d.clear();
	}
}