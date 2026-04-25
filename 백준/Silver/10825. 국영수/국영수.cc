#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct Score {
	int Korean, English, Math;
	string name;
};

bool func(Score &a,Score &b) {
	if (a.Korean != b.Korean) return a.Korean > b.Korean;
	else if (a.English != b.English) return a.English < b.English;
	else if (a.Math != b.Math) return a.Math > b.Math;
	else return a.name < b.name;
}

Score arr[100001];
int main(){
	
	ios_base::sync_with_stdio(false); cin.tie( NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].name >> arr[i].Korean >> arr[i].English >> arr[i].Math;
	}
	sort(arr, arr + n,func);

	for (int i = 0; i < n; i++) {
		cout << arr[i].name << '\n';
	}
	return 0;
}