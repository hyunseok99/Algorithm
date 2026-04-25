#include <iostream>
#include <deque>
#include <cmath>
using namespace std;
	
int k;

// dir = 0 -> 회전 x, 1 -> 시계, 2 -> 반시계
struct sawTooth {
    deque<int> pos;
};

// 시계 -> 반시계, 반시계 -> 시계 방향을 리턴
int sawDir(int dir) {
    if (dir == 1) return -1;
    if (dir == -1) return 1;
}

// dir에 따른 시계, 반시계 이동시키는 함수
void move(int dir, int idx, sawTooth(&arr)[5]) {
    if (dir == 1) {
        int last = arr[idx].pos.back();
        arr[idx].pos.pop_back();
        arr[idx].pos.push_front(last);
    }
    else {
        int front = arr[idx].pos.front();
        arr[idx].pos.pop_front();
        arr[idx].pos.push_back(front);
    }
}

// 회전 명령에 따른 나머지 톱니들의 움직임 
void slide(int idx, int dir, sawTooth(&arr)[5]) {
    int leftTmp = idx;
    int rightTmp = idx;

    // idx 기준 왼쪽 방향 연산
    // for문 이후의 tmp값까지 move 돌리면 됨
    for (int i = idx - 1; i >= 1; i--) {
        if (arr[leftTmp].pos[6] != arr[i].pos[2]) {
            leftTmp = i;
        }
        else {
            break;
        }
    }

    // idx 기준 오른쪽 방향 연산
    for (int i = idx + 1; i <= 4; i++) {
        if (arr[rightTmp].pos[2] != arr[i].pos[6]) {
            rightTmp = i;
        }else {
            break;
        }
    }

    // 톱니바퀴 회전 수행 
    move(dir, idx, arr);
    int newDir = sawDir(dir);
    for (int i = idx - 1; i >= leftTmp; i--) {
        move(newDir, i, arr);
        newDir = sawDir(newDir);
    }
    newDir = sawDir(dir);
    for (int i = idx + 1; i <= rightTmp; i++) {
        move(newDir, i, arr);
        newDir = sawDir(newDir);
    }
}

// 점수의 합을 리턴하는 함수
int getPoint(sawTooth(&arr)[5]) {
    int sum = 0;
    for (int i = 1; i <= 4; i++) {
        if (arr[i].pos[0] == 1) {
            sum += pow(2, (i - 1));
        }
    }
    return sum;
}

int main() {
    sawTooth arr[5];

    for (int i = 1; i <= 4; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 8; j++) {
            arr[i].pos.push_back(tmp[j]-'0');
        }
    }

    cin >> k;

    for (int i = 0; i < k; i++) {
        int idx, dir;
        cin >> idx >> dir;
        slide(idx, dir, arr);
    }

    int res = getPoint(arr);
    cout << res;
    return 0;
}