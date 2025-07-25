#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 3; i++) {
		cin >> n;
		// 동전 가격,  갯수
		vector<pair<int, int>> value;
		int obj = 0;
		for (int j = 0; j < n; j++) {
			int a, b;
			cin >> a >> b;
			value.push_back({ a, b });
			obj += (a * b);
		}
		// 반반 불가
		if (obj % 2 != 0) {
			cout << 0 << "\n";
			continue;
		}

		// 가능 금액
		vector<bool> dp(obj + 1, false);
		dp[0] = true;


		obj = obj / 2;
		
		// dp로 반 나누기 가능한지 검증
		for (int i = 0; i < value.size(); i++) {
			pair<int, int> coin = value[i];
			int price = coin.first;
			int cnt = coin.second;

			// 이 cnt가 10만개일 수도 있어서 최악의 경우 시간 초과 50000 * 10만 -> 50억  
			// 1~n 을 1,2,2^2 ~ 의 조합으로 구현 가능
			// ex) 500 5개 -> 1,2, 2 -> {500, 1000, 1000} -> 0,500 -> 0,500,1000,1500 -> 0,500,1000,1500,2000,2500  모두 구현 가능해짐 
			// 1~cnt 개의 동전을 사용해서 금액을 구성 -> log(cnt) 개로 감소
			vector<int> comb;
			for (int k = 1; 0 < cnt; k*=2) {
				int numTake = min(k, cnt);
				comb.push_back(price * numTake);
				cnt -= numTake;
			}

			for (int j = 0; j < comb.size(); j++) {
				int money = comb[j];
				for (int k = obj; k >= money; k--) {
					if (dp[k - money]) {
						dp[k] = true;
					}
				}
			}

		}

		if (dp[obj]) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}


	return 0;
}