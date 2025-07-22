#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;

/*
	1. n-2개의 원판을 A->C에, n-1번 원판을 B에
	2. n번 원판을 A -> D, n-1번 원판을 B -> D
	3. n-4개의 원판을 C->A에, n-3번 원판을 B에
	4. n-2번 원판은 그대로  C -> D, n-3번 원판을 B->D
	이럼 최소 이동일듯
*/


// 정답 출력용 이동 경로 
queue<pair<char, char>> res;

char change(char c) {
	if (c == 'A') return 'C';
	return 'A';
}

// 일반적인 경로 저장
void saveMove(int start, int end) {
	res.push({ start, end });
	return;
}

// D로 이동하는 경로 저장
void endMove(int start) {
	// n-1번을 start 에서 -> B로 옮기고 
	// n번을 start에서 -> D로 옮기고
	// n-1번을 B에서 -> D로
	res.push({ start,'B' });
	res.push({ start,'D' });
	res.push({ 'B','D' });
	
	return;
}


// 기존 하노이 3개 짜리 이용해서 n-2개를 A에서 C로 옮기는 작업을 수행하고 이 작업이 끝나면 n-1번, n번을 D로 옮기는 과정을 수행하면 될듯 
// recursion은 A, B , C만 이용 
// 재귀로 A -> C 이동이 끝나면 n, n-1 이동 저장 
// 이 경우는 전역으로 입력 받은 n이 3이상일 떄 최소 1개는 C로 보내야 할 때 필요 마지막 C로 보낸 1개는 다시 D로 보내줘야 함 
void recursion(int n, char start, char end, char use) {
	if (n < 1) return;
	if (n == 1) {
		saveMove(start, end);
	} else {
		// A -> C , A -> B , B -> C 이런식으로 A의 n-2개를 C로 이동 
		recursion(n - 1, start, use, end);
		// A -> C로 이동할 떄의 동선 저장
		saveMove(start,end);
		recursion(n - 1, use, end, start);
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;

	if (n < 3) {
		if (n == 1) {
			saveMove('A', 'D');
		}
		else {
			endMove('A');
		}

	}
	else {
		int idx = n - 2;
		// 처음에 n-2 개를 A -> C로 보냈으면 다음에는 C -> A로 보내야 함 
		char firstStart = 'A';
		char firstEnd = 'C';
		while (idx >= 0) {
			// 짝수일 때는 문제가 없는데 홀수면 한개가 남아있음 -> 이거 따로 처리 필요함
			// n-2개를 A -> C로 이동 후에 n, n-1번 D로 이동
			recursion(idx, firstStart, firstEnd, 'B');
			endMove(firstStart);
			firstStart = change(firstStart);
			firstEnd = change(firstEnd);
			// 마지막 1개만 남은경우
			if (idx == 1) {
				// 홀수개인 경우
				if (n % 2 != 0) {
					saveMove(firstStart, 'D');
				}
				else {
					endMove(firstStart);
				}
			}
			idx = idx - 2;
		}
		// 만약 idx = 1 이면 

	}


	cout << res.size() << "\n";
	while (!res.empty()) {
		pair<char, char>move = res.front();
		res.pop();
		cout << move.first << " " << move.second << "\n";
	}

	return 0;
}
