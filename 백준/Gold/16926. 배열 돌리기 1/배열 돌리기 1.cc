#include <iostream>
using namespace std;

int arr[301][301];

void Func(int n,int m,int t) { //t=회전 횟수
	if (t == 0) return;

	int k = min(n, m) / 2; // 회전 시작 좌표 (0,0),(1,1)....(k-1,k-1)

	for (int i = 0; i < k; i++) {//

		int x = i; int y = i;   //arr[x][y]->회전 시작 좌표
		int z = arr[x][y]; // 꼭짓점 좌표 값 저장용 
	
		while (x<n-1-i) { //아래로 이동	
			int next = arr[x + 1][y];
			arr[x + 1][y] = z;
			z = next;
			x++;
		}	

		while (y < m - 1 - i) {//오른쪽으로 이동
			int next = arr[x][y + 1];
			arr[x][y + 1] =z;
			z = next;
			y++;
		}

		while (x>=i+1) {//위쪽으로 이동
			int next = arr[x-1][y];
			arr[x - 1][y] = z;
			z = next;
			x--;
		}

		while (y >= i + 1) {//왼쪽으로 이동
			int next = arr[x][y - 1];
			arr[x][y - 1] = z;
			z = next;
			y--;
		}
	}
	Func(n, m, t - 1);
}

int main() {
	int n, m, r;
	cin >> n >> m >> r;

	if (min(n, m) % 2 != 0) {
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	Func(n,m,r);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}