#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;

struct room {
	char type;
	int price = 0;
	vector<int> go;
};

bool check(room& A, int& user) {
	if (A.type == 'E') return true;
	if (A.type == 'L') {
		if (A.price > user) {
			user = A.price;
		}
		return true;
	}
	if (A.type == 'T') {
		if (A.price > user) return false;
		else {
			user -= A.price;
			return true;
		}
	}
	return false;
}

bool func(vector<room>& node, int& user) {
	// 큐를 활용해서 목적지까지 도달 가능 여부 경로 저장 
	// 처음 방문할 위치 저장 
	queue<int> q;
	q.push(1);

	vector<bool> flag(n + 1, false);

	while (!q.empty()) {
		int idx = q.front();
		q.pop();

		// 이동 가능 
		if (!flag[idx] && check(node[idx], user)) {
			flag[idx] = true;
			// n번 노드 방문 가능
			if (idx == n) {
				return true;
			}
			for (int i = 0; i < node[idx].go.size(); i++) {
				q.push(node[idx].go[i]);
			}
		}
	}

	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> n;
		if (n == 0) break;
		int user = 0;
		// 1~n 
		vector<room> node(n + 1);
		for (int i = 1; i <= n; i++) {
			room tmp;
			cin >> tmp.type >> tmp.price;
			while (1) {
				int num;
				cin >> num;
				if (num == 0) break;
				tmp.go.push_back(num);
			}
			node[i] = tmp;
		}

		// 시작 위치에서 불가능한 경우 
		if (!check(node[1], user)) {
			cout << "No" << "\n";
		}
		else {
			if (func(node, user)) {
				cout << "Yes" << "\n";
			}
			else {
				cout << "No" << "\n";
			}
		}
	}

	return 0;
}