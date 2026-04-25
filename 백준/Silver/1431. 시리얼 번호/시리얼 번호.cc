#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

string num = "0123456789";
vector<string> v;

bool compare(string& a,string& b ) {
	int asum = 0; int bsum = 0;
	if (a.length() != b.length()) return a.length() < b.length();
	for (int i = 0; i < a.length(); i++) {
		if (num.find(a[i]) <= num.length())  asum += (a[i] - '0');
	}
	for (int i = 0; i < b.length(); i++) {
		if (num.find(b[i]) <= num.length()) bsum += (b[i] - '0');
	}
	if (asum != bsum) return asum < bsum;
	else return a < b;
}

int main(){
	
	ios_base::sync_with_stdio(false); cin.tie( NULL);
	
	int n; cin >> n;
	cin.ignore();
	string s;
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		v.push_back(s);
	}
	sort(v.begin(), v.end(), compare);

	for (auto& k : v) cout << k << endl;
	
	return 0;
}