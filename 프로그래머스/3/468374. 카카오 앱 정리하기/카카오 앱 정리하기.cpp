#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

// 앱의 좌표와 크기를 관리
struct App {
    int id, r, c, h, w;
};

int n, m;
int dy[] = {0, 0, 1, 0, -1}; // 1:우, 2:하, 3:좌, 4:상
int dx[] = {0, 1, 0, -1, 0};
int global_board[15][15]; 
map<int, App> apps;
queue<int> teleport_q;    

void erase_app(int id) {
    App& a = apps[id];
    for (int i = 0; i < a.h; ++i) {
        for (int j = 0; j < a.w; ++j) {
            int rr = a.r + i;
            int cc = a.c + j;
            if (rr >= 0 && rr < n && cc >= 0 && cc < m) {
                if (global_board[rr][cc] == id) {
                    global_board[rr][cc] = 0;
                }
            }
        }
    }
}

// 보드에 해당 앱을 그리는 함수 (보드 안에 있는 영역만)
void draw_app(int id) {
    App& a = apps[id];
    for (int i = 0; i < a.h; ++i) {
        for (int j = 0; j < a.w; ++j) {
            int rr = a.r + i;
            int cc = a.c + j;
            if (rr >= 0 && rr < n && cc >= 0 && cc < m) {
                global_board[rr][cc] = id;
            }
        }
    }
}

// "한 칸 밀고, 겹치면 걔도 밀기"
void step_forward(int id, int dir) {
    App& a = apps[id];
    int next_r = a.r + dy[dir];
    int next_c = a.c + dx[dir];

    // 1. 선을 넘는 순간 보드에서 제거하고 큐 대기
    if (dir == 1 && next_c + a.w > m) { erase_app(id); teleport_q.push(id); return; }
    if (dir == 2 && next_r + a.h > n) { erase_app(id); teleport_q.push(id); return; }
    if (dir == 3 && next_c < 0)       { erase_app(id); teleport_q.push(id); return; }
    if (dir == 4 && next_r < 0)       { erase_app(id); teleport_q.push(id); return; }

    // 2. 내가 전진할 영역에 방해물이 있으면 걔부터 민다.
    vector<int> targets;
    for (int i = 0; i < a.h; ++i) {
        for (int j = 0; j < a.w; ++j) {
            int rr = next_r + i;
            int cc = next_c + j;
            if (rr >= 0 && rr < n && cc >= 0 && cc < m) {
                int target_id = global_board[rr][cc];
                if (target_id != 0 && target_id != id) {
                    bool found = false;
                    for (int t : targets) if (t == target_id) found = true;
                    if (!found) targets.push_back(target_id);
                }
            }
        }
    }

    // 재귀적으로 방해물 밀어내기
    for (int t : targets) {
        step_forward(t, dir);
    }

    // 3. 앞길이 뚫렸으니 내 꼬리를 지우고, 머리를 채워 넣는다.
    erase_app(id);
    a.r = next_r;
    a.c = next_c;
    draw_app(id);
}

vector<vector<int>> solution(vector<vector<int>> board, vector<vector<int>> commands) {
    apps.clear();
    while(!teleport_q.empty()) teleport_q.pop();
    
    n = board.size();
    m = board[0].size();
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            global_board[r][c] = board[r][c];
        }
    }

    struct BoundingBox { int min_r, max_r, min_c, max_c; };
    map<int, BoundingBox> bboxes;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            int id = global_board[r][c];
            if (id != 0) {
                if (bboxes.find(id) == bboxes.end()) bboxes[id] = {r, r, c, c};
                else {
                    bboxes[id].min_r = min(bboxes[id].min_r, r);
                    bboxes[id].max_r = max(bboxes[id].max_r, r);
                    bboxes[id].min_c = min(bboxes[id].min_c, c);
                    bboxes[id].max_c = max(bboxes[id].max_c, c);
                }
            }
        }
    }
    for (auto& p : bboxes) {
        apps[p.first] = {p.first, p.second.min_r, p.second.min_c,
                         p.second.max_r - p.second.min_r + 1,
                         p.second.max_c - p.second.min_c + 1};
    }

    // 커맨드 시뮬레이션 시작
    for (const auto& cmd : commands) {
        int target_id = cmd[0];
        int dir = cmd[1];
        if (apps.find(target_id) == apps.end()) continue;

        // 1. 타겟 앱 밀기
        step_forward(target_id, dir);

        while (!teleport_q.empty()) {
            int tid = teleport_q.front();
            teleport_q.pop();

            App& a = apps[tid];
            int steps = 0;
            
            // 반대편 바깥 위치로 순간이동 세팅
            if (dir == 1) { a.c = -a.w; steps = a.w; }
            else if (dir == 2) { a.r = -a.h; steps = a.h; }
            else if (dir == 3) { a.c = m; steps = a.w; }
            else if (dir == 4) { a.r = n; steps = a.h; }

            for (int i = 0; i < steps; ++i) {
                step_forward(tid, dir);
            }
        }
    }

    // 최종 보드 복원
    vector<vector<int>> answer(n, vector<int>(m, 0));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            answer[r][c] = global_board[r][c];
        }
    }

    return answer;
}