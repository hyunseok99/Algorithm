#include <iostream>
#include <list>
#include <string>
using namespace std;

list<char> Mylist;
list<char>::iterator cursor;
int main() {
	int n;
	cin >> n;
	string str;
	for (int k = 0; k < n; k++) {
		cin >> str;
		cursor = Mylist.begin();

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '<') {
				if (cursor!=Mylist.begin()) cursor--;
			}
			else if (str[i] == '>') {
				if (cursor != Mylist.end())cursor++;
			}
			else if (str[i] == '-')
			{
				if (cursor != Mylist.begin()) {
					cursor--;
					cursor = Mylist.erase(cursor); //삭제 후 다음 주소 return
				}
			}
			else {
				Mylist.insert(cursor, str[i]);
			}
		}
		while (!Mylist.empty()) {
			cout << Mylist.front();
			Mylist.pop_front();
		}
		cout << '\n';
	}
	return 0;
}
