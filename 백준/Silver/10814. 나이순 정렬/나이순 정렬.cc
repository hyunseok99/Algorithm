#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct member {
	int num, age;
	string name;
};

bool compare(member& a, member& b) {
	if (a.age != b.age) return a.age < b.age;
	else return a.num < b.num;
}

int main() {
	
	ios_base::sync_with_stdio(false); cin.tie( NULL);

	int n; cin >> n;
	member* m = new member[n];

	for (int i = 0; i < n; i++) {
		cin >> m[i].age >> m[i].name;
		m[i].num = i;
	}
	
	sort(m, m + n, compare);

	for (int i = 0; i < n; i++) {
		cout << (m + i)->age << " " << (m + i)->name << "\n";
	}

	return 0;
}