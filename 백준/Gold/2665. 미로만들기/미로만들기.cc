#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

// 2665

// 0 검은방 , 1 흰방
// 검은색 방의 갯수 m면 mC0,1,2, ... 될 때 까지 ㄱㄱ

// 1. 조합 찾기  -> 2. dfs를 통해 끝방 도착 여부 확인 -> 3. 반복
// 조합이 약해서 조합 부분을 일부러 써서 구현했는데 시간 초과 ㅋㅋ 걍 바꾸는 검은색을 누적하는 방식으로 가야 할듯
// 1. bfs 통해서 끝방 도착 여부 확인 + 추가적으로 이동 과정에서 검은방 지나는 경우 cnt 누적
int n, m;


void bfs(vector<vector<int> > copy_v);

// input:모든방의 위치 정보가 들어있는 벡터 복사본
// bfs 수행하면서 특정위치에서 지나온 검은방 갯수 갱신
void bfs(vector<vector<int>> copy_v) {

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    // 방문 여부와, 지나온 검은방 갯수
    vector<vector<int> > check(n, vector<int>(n, 0));
    vector<vector<int> > num(n, vector<int>(n, 0));

    // 좌표, 지나온 검은방 수
    queue<pair<pair<int, int>, int> > move;
    move.push({{0, 0}, 0} );
    while (!move.empty()) {
        pair<pair<int, int>,int> tmp = move.front();
        move.pop();
        check[tmp.first.first][tmp.first.second] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = tmp.first.first + dx[i];
            int ny = tmp.first.second + dy[i];
            int blackCnt = tmp.second;
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if (copy_v[nx][ny] == 0) {
                    blackCnt++;
                }
                if (check[nx][ny] == 1 ) {
                    if (num[nx][ny] > blackCnt) {
                        num[nx][ny] = blackCnt;
                        move.push({{nx, ny}, blackCnt});
                    }
                }else {
                    num[nx][ny] = blackCnt;
                    check[nx][ny] = 1;
                    move.push({{nx, ny}, blackCnt});
                }
            }
        }
    }
    cout<<num[n-1][n-1];
}

int main() {
    cin >> n;
    // 전체 배열
    vector<vector<int> > v(n, vector<int>(n, 1));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if ((s[j]-'0') == 0) {
                v[i][j] = s[j]-'0';
                m++;
            }
        }
    }

    bfs(v);
    return 0;
}
