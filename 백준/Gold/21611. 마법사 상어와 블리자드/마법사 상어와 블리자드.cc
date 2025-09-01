#include <iostream>
#include <vector>
#include <queue>
#include <deque> // 불필요할 수 있지만, 기존 코드에 있어 일단 유지
#include <algorithm>
#include <utility>

using namespace std;

int n, m;
long long glassCnt[4] = { 0,0,0,0 }; // 폭발 구슬 총합을 저장하므로 long long으로 변경
// 0 상 하 좌 우 (idx: 1~4)
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };

void boom(queue<int>& q, vector<vector<int>>& arr); // q를 레퍼런스로 받도록 수정
void move(vector<vector<int>>& arr);

// 방향 전환 함수: 현재 방향에서 다음 나선형 방향으로 변경
int changeDir(int dir) {
    if (dir == 3) { // 좌 -> 하
        return 2;
    } else if (dir == 2) { // 하 -> 우
        return 4;
    } else if (dir == 4) { // 우 -> 상
        return 1;
    } else { // 상 -> 좌
        return 3;
    }
}

// 블리자드 수행 함수
void doBlizard(vector<vector<int>>& arr, int dir, int range) {
    int sharkY = (n + 1) / 2;
    int sharkX = sharkY;

    for (int i = 0; i < range; i++) {
        int ny = sharkY + dy[dir];
        int nx = sharkX + dx[dir];

        if (ny >= 1 && ny <= n && nx >= 1 && nx <= n) {
            arr[ny][nx] = 0; // 구슬 파괴
        }
        sharkY = ny;
        sharkX = nx;
    }

    // 블리자드 후 구슬 이동
    move(arr);
}

// 빈 곳 구슬 이동 (나선형);
void move(vector<vector<int>>& arr) {
    int startY = (n + 1) / 2;
    int startX = startY;

    queue<int> glassQ; // 이동 후 구슬들을 임시로 저장할 큐

    int currentY = startY;
    int currentX = startX;
    int len = 1;
    int dir = 3; // 시작 방향: 좌
    int movedCount = 0; // 이동시킨 칸의 개수 (상어 위치 제외 N*N-1)

    // 나선형으로 구슬을 수집
    while (true) {
        for (int i = 0; i < 2; i++) { // 각 길이마다 두 번 방향 전환
            for (int j = 0; j < len; j++) {
                currentY += dy[dir];
                currentX += dx[dir];

                // 보드 범위를 벗어나면 종료
                if (currentY < 1 || currentY > n || currentX < 1 || currentX > n) {
                    goto end_move_loop; // 이중 루프 탈출
                }

                if (arr[currentY][currentX] != 0) {
                    glassQ.push(arr[currentY][currentX]);
                }
            }
            dir = changeDir(dir);
        }
        len++; // 한 바퀴 돌았으니 길이 증가
    }
    end_move_loop:;

    // 수집된 구슬들을 이용하여 폭발 처리
    boom(glassQ, arr);
}

// 구슬 폭발 및 복사 함수
void boom(queue<int>& glassQ, vector<vector<int>>& arr) {
    // 1. 폭발 단계 (연쇄 폭발 처리)
    bool exploded_in_round = false;
    do {
        exploded_in_round = false;
        if (glassQ.empty()) break;

        vector<int> temp_glass; // 폭발 후 남은 구슬들을 임시로 저장
        int current_val = 0;
        int count = 0;

        // 큐에서 모든 구슬을 꺼내면서 폭발 처리
        while (!glassQ.empty()) {
            int marble = glassQ.front();
            glassQ.pop();

            if (current_val == 0) { // 첫 구슬이거나 새로운 연속 시작
                current_val = marble;
                count = 1;
            } else if (current_val == marble) { // 같은 구슬 연속
                count++;
            } else { // 다른 구슬 등장 (이전 연속 그룹 처리)
                if (count >= 4) {
                    glassCnt[current_val] += count;
                    exploded_in_round = true;
                } else {
                    for (int i = 0; i < count; ++i) {
                        temp_glass.push_back(current_val);
                    }
                }
                current_val = marble;
                count = 1;
            }
        }

        // 큐가 비고 남은 마지막 연속 그룹 처리
        if (count >= 4) {
            glassCnt[current_val] += count;
            exploded_in_round = true;
        } else if (current_val != 0) { // 0이 아니면 유효한 구슬
            for (int i = 0; i < count; ++i) {
                temp_glass.push_back(current_val);
            }
        }

        // temp_glass에 남은 구슬들을 다시 glassQ로 이동하여 다음 폭발 라운드 준비
        for (int marble : temp_glass) {
            glassQ.push(marble);
        }

    } while (exploded_in_round); // 폭발이 발생했으면 다시 반복

    // 2. 구슬 복사 단계
    queue<int> newQ; // 최종적으로 보드에 배치될 구슬 정보 (개수, 값)
    if (!glassQ.empty()) {
        int current_val = glassQ.front();
        glassQ.pop();
        int count = 1;

        while (!glassQ.empty()) {
            int marble = glassQ.front();
            glassQ.pop();

            if (current_val == marble) {
                count++;
            } else {
                // 개수 푸시 전에 용량 확인
                if (newQ.size() + 2 > (n * n - 1)) { // 개수와 값 두 개를 푸시할 공간이 있어야 함
                    break;
                }
                newQ.push(count);
                newQ.push(current_val);
                current_val = marble;
                count = 1;
            }
        }
        // 마지막 그룹 처리
        if (newQ.size() + 2 <= (n * n - 1)) { // 마지막 그룹도 공간 확인
            newQ.push(count);
            newQ.push(current_val);
        } else if (newQ.size() + 1 <= (n * n - 1)) { // 개수만 들어갈 공간이 있다면
             newQ.push(count);
        }
    }


    // 3. arr 갱신 (새로운 구슬들 배치)
    vector<vector<int>> newArr(n + 1, vector<int>(n + 1, 0)); // 0으로 초기화된 새 보드

    int currentY = (n + 1) / 2;
    int currentX = currentY;
    int len = 1;
    int dir = 3; // 시작 방향: 좌

    while (true) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < len; j++) {
                currentY += dy[dir];
                currentX += dx[dir];

                // 보드 범위를 벗어나거나, 배치할 구슬이 없으면 종료
                if (currentY < 1 || currentY > n || currentX < 1 || currentX > n || newQ.empty()) {
                    goto end_place_loop; // 이중 루프 탈출
                }

                newArr[currentY][currentX] = newQ.front();
                newQ.pop();
            }
            dir = changeDir(dir);
        }
        len++;
    }
    end_place_loop:;

    arr = newArr; // 메인 보드 업데이트
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int dir, range;
        cin >> dir >> range;
        doBlizard(arr, dir, range);
    }

    long long res = 0; // 결과도 long long
    for (int i = 1; i <= 3; i++) {
        res += (glassCnt[i] * i);
    }
    cout << res;

    return 0;
}