#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int n, m;

// 상 하 좌 우
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

// 섬 구분 짓기
void numbering(int y, int x, int& num, vector<vector<int>>& arr) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		if (arr[tmp.first][tmp.second] == num) continue;
		// 섬 넘버링 2~x
		arr[tmp.first][tmp.second] = num;
		for (int dir = 0; dir < 4; dir++) {
			int ny = tmp.first + dy[dir];
			int nx = tmp.second + dx[dir];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] == 1) {
				q.push({ ny, nx });
			}
		}
	}
	num++;
	return;
}


// 특정 섬에서 다른 섬까지 다리 건설 여부 및 가능한 경우 최단 길이 갱신
void getDist(vector<vector<int>>& dist, vector<vector<int>>& arr, int num) {
	// 2번 섬부터 num-1번 섬까지 
	for (int i = 2; i < num - 1; i++) {
		int cur = i; // 현재 선택 섬 
		for (int j = i + 1; j < num; j++) {
			int connected = j;

			// i,j 섬 사이의 최단 거리 
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < m; x++) {
					if (arr[y][x] == i) {
						// 가로의 경우 
						int distX = 0;
						int startY = y;
						int startX = x;
						bool isConnected = false;
						// 증가하는 경우
						while (startX < m-1) {
							startX++;
							if (arr[y][startX] == i && distX == 0) {
								continue;
							}
							else if (arr[y][startX] == 0) {
								distX++;
							}
							else if (arr[y][startX] == connected) {
								isConnected = true;
								break;
							}
							else {
								// 육지를 지나가 다리 놓기 불가
								break;
							}
						}

						if (isConnected && distX > 1) {
							dist[i][j] = min(dist[i][j], distX);
							dist[j][i] = min(dist[j][i], distX);
						}
						// 감소하는 경우
						startX = x;
						distX = 0;
						isConnected = false;
						while (startX > 0) {
							startX--;
							// ㅂ 형태의 땅일 경우 다리 x 
							if (arr[y][startX] == i && distX == 0) {
								continue;
							}
							else if (arr[y][startX] == 0) {
								distX++;
							}
							else if (arr[y][startX] == connected) {
								isConnected = true;
								break;
							}
							else {
								// 육지를 지나가 다리 놓기 불가
								break;
							}
						}
						if (isConnected && distX > 1) {
							dist[i][j] = min(dist[i][j], distX);
							dist[j][i] = min(dist[j][i], distX);
						}

						// 세로
						int distY = 0;
						isConnected = false;
						while (startY < n-1) {
							startY++;
							if (arr[startY][x] == i && distY == 0){
								continue;
							}
							else if (arr[startY][x] == 0) {
								distY++;
							}
							else if (arr[startY][x] == connected) {
								isConnected = true;
								break;
							}
							else {
								// 육지를 지나가 다리 놓기 불가
								break;
							}
						}
						if (isConnected && distY > 1) {
							dist[i][j] = min(dist[i][j], distY);
							dist[j][i] = min(dist[j][i], distY);
						}

						distY = 0;
						startY = y;
						isConnected = false;
						while (startY > 0) {
							startY--;
							if (arr[startY][x] == i && distY == 0) {
								continue;
							}
							else if (arr[startY][x] == 0) {
								distY++;
							}
							else if (arr[startY][x] == connected) {
								isConnected = true;
								break;
							}
							else {
								// 육지를 지나가 다리 놓기 불가
								break;
							}
						}
						if (isConnected && distY > 1) {
							dist[i][j] = min(dist[i][j], distY);
							dist[j][i] = min(dist[j][i], distY);
						}
					}
				}
			}
		}
	}
}

struct Edge {
	int u, v;
	int weight;

	bool operator<(Edge& b) const {
		return weight < b.weight;
	}
};

class DSU {
public:
	vector<int> parents;
	int components; // 연결된 수

	DSU(int n) { // 2~ n-1 번 섬 
		parents.resize(n);
		for (int i = 2; i < n; i++) {
			parents[i] = i;
		}
		components = n - 2;
	}

	int findRoot(int v) {
		if (v == parents[v]) return v;
		return parents[v] = findRoot(parents[v]);
	}

	bool unionSet(int a, int b) {
		a = findRoot(a);
		b = findRoot(b);

		if (a != b) {
			parents[b] = a;
			components--;
			return true;
		}
		return false;
	}
};

// 섬 조합 구하기 -> 최소 스패닝 트리 구현 가능 여부로 
int getMST(vector<vector<int>> dist, int num) {
	int res = -1;
	vector<Edge> edges;
	for (int i = 2; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			if (dist[i][j] != 101) { // 101이면 연결 불가
				edges.push_back({ i, j, dist[i][j] });
			}
		}
	}

	// 크루스칼 
	sort(edges.begin(), edges.end());

	DSU dsu(num);
	int weight = 0;

	for (auto& edge : edges) {
		// 유니온 가능하면
		if (dsu.unionSet(edge.u, edge.v)) {
			weight += edge.weight;
		}

		// mst 생성 여부 확인
		if (dsu.components == 1) {
			break;
		}
	}

	if (dsu.components == 1) {
		return weight;
	}
	else {
		return -1;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	// 섬 구분하기 1,2,3 ... x개의 섬을 구분 
	int num = 2; // 섬은 2 ~ (num-1) 까지 존재
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				numbering(i, j, num, arr);
			}
		}
	}


	// 다리를 놓을 섬들의 조합을 구성 및 거리 계산 
	vector<vector<int>> dist(num, vector<int>(num, 101)); // 2~ (num-1)번 까지의 다리 설치시 최단 거리 저장 
	getDist(dist, arr, num);

	cout << getMST(dist, num);
	return 0;
}