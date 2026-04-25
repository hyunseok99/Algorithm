#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct player {
	int Country, Num, Score;
};

vector<player> v;
int medal[101] = { 0, };

bool compare(player& a, player& b) {
	 return a.Score > b.Score;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	player p;
	for (int i = 0; i < n; i++) {
		cin >> p.Country >> p.Num >> p.Score;
		v.push_back(p);
	}

	sort(v.begin(), v.end(), compare);



	int cnt = 0;

	for (int i = 0; i < v.size(); i++) {
		medal[v[i].Country] += 1;
		if (medal[v[i].Country] > 2) continue;
		cnt++;
		cout << v[i].Country << " " << v[i].Num << '\n';
		if (cnt == 3) break;
	}
	return 0;
}