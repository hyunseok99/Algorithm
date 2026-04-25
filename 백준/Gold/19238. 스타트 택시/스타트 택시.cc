#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

// 전역 변수들
int n, m, fuel;
int cnt = 0;

void bfs(pair<int, int> taxi, vector<vector<int>>& v);

// 상 하 좌 우
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

// 우선순위 큐 비교 함수
struct comp {
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        if (a.first != b.first) {
            return a.first > b.first; // 거리가 가까운 순
        }
        if (a.second.first != b.second.first) {
            return a.second.first > b.second.first; // 행이 작은 순
        }
        return a.second.second > b.second.second; // 열이 작은 순
    }
};

map<pair<int, int>, pair<int, int>> mMap;
map<pair<int, int>, bool> check;

// 승객 출발지로부터 목적지까지의 거리와 연료 계산
void getPickerDist(pair<int, pair<int, int>> picked, pair<int, int> dest, vector<vector<int>>& v) {
    int firstFuelConsume = picked.first;
    int secondFuelConsume = -1;
    
    vector<vector<bool>> flag(n + 1, vector<bool>(n + 1, false));
    queue<pair<int, pair<int, int>>> q;

    q.push({ 0, picked.second });
    flag[picked.second.first][picked.second.second] = true;

    while (!q.empty()) {
        int dist = q.front().first;
        int curY = q.front().second.first;
        int curX = q.front().second.second;
        q.pop();

        if (curY == dest.first && curX == dest.second) {
            secondFuelConsume = dist;
            break;
        }

        for (int dir = 0; dir < 4; dir++) {
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && v[ny][nx] == 0 && !flag[ny][nx]) {
                flag[ny][nx] = true;
                q.push({ dist + 1, {ny, nx} });
            }
        }
    }
    
    // 목적지에 도달하지 못한 경우
    if (secondFuelConsume == -1) {
        cout << -1;
        exit(0);
    }

    // 연료 계산
    int totalFuelUsed = firstFuelConsume + secondFuelConsume;
    if (fuel < totalFuelUsed) {
        cout << -1;
        exit(0);
    }
    
    fuel -= totalFuelUsed;
    fuel += secondFuelConsume * 2; // 소모 연료의 2배 충전
    
    check[picked.second] = true;
    cnt++;
    
    bfs(dest, v);
}

// 택시 위치에서 가장 가까운 승객 찾기
void bfs(pair<int, int> taxi, vector<vector<int>>& v) {
    if (cnt == m) {
        cout << fuel;
        exit(0);
    }

    vector<vector<bool>> flag(n + 1, vector<bool>(n + 1, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> customer_pq;
    
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, taxi });
    flag[taxi.first][taxi.second] = true;
    bool found_customer = false;

    while (!q.empty()) {
        int dist = q.front().first;
        int curY = q.front().second.first;
        int curX = q.front().second.second;
        q.pop();

        // 가장 가까운 승객을 찾았으면, 더 먼 거리는 탐색할 필요가 없음
        if (found_customer && customer_pq.top().first < dist) {
             break;
        }
        
        // 현재 위치가 승객 출발지이고, 아직 운반하지 않은 승객이라면
        if (mMap.count({curY, curX}) && check.count({curY, curX}) == 0) {
            customer_pq.push({ dist, {curY, curX} });
            found_customer = true;
        }

        for (int dir = 0; dir < 4; dir++) {
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && v[ny][nx] == 0 && !flag[ny][nx]) {
                flag[ny][nx] = true;
                q.push({ dist + 1, {ny, nx} });
            }
        }
    }
    
    // 이동 가능한 손님이 없는 경우
    if (customer_pq.empty()) {
        cout << -1;
        exit(0);
    }
    
    pair<int, pair<int, int>> picked = customer_pq.top();
    getPickerDist(picked, mMap[picked.second], v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> fuel;

    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    pair<int, int> taxi;
    cin >> taxi.first >> taxi.second;

    for (int i = 0; i < m; i++) {
        pair<int, int> start, dest;
        cin >> start.first >> start.second >> dest.first >> dest.second;
        mMap[start] = dest;
    }

    bfs(taxi, v);

    return 0;
}