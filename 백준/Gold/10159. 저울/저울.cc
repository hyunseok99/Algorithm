#include <iostream>
#include <vector>
using namespace std;



int main() {
	int n,m,a,b;
	cin >> n >> m;
	int** Table = new int* [n];  // Table[n][n] 동적할당
	
	for (int i = 0; i < n; i++) {
		Table[i] = new int[n];
	}
	
	for (int i = 0; i < n; i++) { // reset
		for (int j = 0; j < n; j++) {
			Table[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		--a; --b;
		Table[a][b] = 1;   //a>b =>1 , b<a -> -1
		Table[b][a] = -1;
	}
		
	for (int k =0 ; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++){
				if (Table[i][k] == Table[k][j] && Table[i][k])
					Table[i][j] = Table[i][k];
			}
		}
	}
	

	for (int i = 0; i < n; i++) {
		int cnt = -1; //(0,0),(1,1) .. 같은애들도 새니깐 시작 -1
		for (int j = 0; j < n; j++) {
			if (Table[i][j] == 0) cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}