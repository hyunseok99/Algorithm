#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;

// 시작 도시로 부터 방문 가능한 도시들 갱신
// 입력 받는 경로에서 첫 경로로 부터 갈 수 있는 곳을 모두 갱신하여
// 첫 도시부터 나머지 도시로 이동 가능 여부를 체크
// ex) 1 -> 2 -> 3 -> 5 -> 4 에서 
// 1 -> 2 , 1 ->3, 1->5, 1 -> 4 이런식으로 만약 못가는 경우 있으면 NO
void updateConnection(vector<vector<int>>& node, int cur) {

	// 없다면 해당 지점에서 이동 가능한 곳을 이용해서 연산 
	stack<int> s; // 이동 가능 도시 담을 스택
	vector<bool> flag(n + 1, false); // 도시 방문 여부

	s.push(cur);
	flag[cur] = true;

	while (!s.empty()) {
		int from = s.top();
		s.pop();

		for (int to = 1; to <= n; to++) {
			if (node[from][to] == 1 && !flag[to]) {
				flag[to] = true;
				s.push(to);
				// 방문 가능 경로 추가
				node[cur][to] = 1;
				node[to][cur] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<int>> node(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> node[i][j];
			node[j][i] = node[i][j];
			// 자기 자신으로 이동은 가능하게 수정
			if (i == j) {
				node[i][j] = 1;
			}
		}
	}

	// 계획 경로 
	vector<int> plan(m);
	for (int cur = 0; cur < m; cur++) {
		cin >> plan[cur];
	}
	updateConnection(node, plan[0]);

	bool flag = true;
	for (int i = 1; i < plan.size(); i++) {
		if (node[plan[0]][plan[i]] != 1) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}