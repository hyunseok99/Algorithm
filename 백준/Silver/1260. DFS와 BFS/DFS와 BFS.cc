#include<iostream>
#include <vector>
#include<queue>
using namespace std;

struct Compare{
	bool operator()(int a, int b) {
		return a > b;
	}
};

void DFS(int);
void BFS(int);
priority_queue<int,vector<int>,Compare>* q;
priority_queue<int, vector<int>, Compare>* cq;
queue<int> qq;
bool* check;


int main()
{
	int n, m, v;
	cin >> n >> m >> v;
	check = new bool[n+1];
	q = new priority_queue<int,vector<int>,Compare>[n+1];
	cq= new priority_queue<int, vector<int>, Compare>[n + 1];
	fill(check, check + n+1,false);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		q[a].push(b);
		q[b].push(a);
		cq[a].push(b);
		cq[b].push(a);

	}
	DFS(v);
	cout << endl;
	while (!qq.empty()) qq.pop();
	fill(check, check + n + 1, false);
	BFS(v);
	return 0;
}

void DFS(int v) {
	check[v] = true;	
	cout << v << " ";
	while (!q[v].empty()) {
		int temp = q[v].top(); q[v].pop();
		if (!check[temp]) {
			DFS(temp);
		}
	}
}

void BFS(int v) {
	qq.push(v);
	check[v] = true;
	while (!qq.empty()) {
		int temp = qq.front(); qq.pop();
		cout << temp << " ";
		while (!cq[temp].empty()) {
			int temp2 = cq[temp].top(); cq[temp].pop();
			if (!check[temp2]) {
				qq.push(temp2);
				check[temp2] = true;
			}
		}
	}
}

