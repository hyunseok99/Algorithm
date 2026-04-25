#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <set>
#include <map>
#include <numeric>
using namespace std;

int n;
int res[1000001];
bool check[1000001];
vector<int> card;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		card.push_back(tmp);
		check[tmp] = true;
	}


	for (int i = 0; i < n; i++) {
		// 해다 카드의 배수 탐색 및 점수 계산
		for (int j = card[i] * 2; j < 1000001; j += card[i]) {
			if (check[j]) {
				res[card[i]]++;
				res[j]--;
			}
		}

	}

	for (int i = 0; i < n; i++) {
		cout << res[card[i]] << " ";
	}

	return 0;
}