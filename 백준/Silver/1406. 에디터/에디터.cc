#include <iostream>
#include <list>
#include <string>
using namespace std;

list<char> ChList;
list<char>::iterator it;


int main() {
	string str;
	char n; // 명령어
	int m;
	it = ChList.end();
	cin >> str;
	cin >> m;

	for (int i = 0; i < str.size(); i++) { //편집기에 입력
		ChList.push_back(str[i]);
	}
	
	for (int i = 0; i < m; ++i) {
		cin >> n;
		if (n == 'L') {
			if (it != ChList.begin()) --it;
		}
		else if (n == 'D') {
			if (it != ChList.end()) ++it;
		}
		else if (n == 'B') {
			if (it != ChList.begin()) {
				--it;
				it=ChList.erase(it); //it=ChList.erase(it) 안하면 -> iterator imcopatible error
			}// erase후에 it는 그 다음 위치를 잃어버림, erase 함수의 리턴 값이 삭제 원소 다음에 있는 원소 iterator라 이거 이용
		}
		else if (n == 'P') {
			char k; cin >> k;
			ChList.insert(it, k);
		}
	}

	for (auto k:ChList) {
		cout << k;
	}
	return 0;
}