#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// 1074

// n > 1 일 때 2^n-1 * 2^n-1

int n, res;

// 재귀로 4등분이 더이상 안되면 끝
// input: 구할 좌표,4등분 하는 길이
void func(int r, int c, int div) {
    // div=1 이면 크기 4인 사분면 끝임
    if (div == 1) {
        if (r == 0 && c == 0) {
            res += 0;
        } else if (r == 0 && c == 1) {
            res += 1;
        } else if (r == 1 && c == 0) {
            res += 2;
        } else if (r == 1 && c == 1) {
            res += 3;
        }
        cout << res;
        return;
    }

    // 행이 속하는 좌표 x,y -> (0, 0) , (0, 1), (1, 0), (1,1) 각각 사분면 좌상단,우상단,좌하단,우하단
    // 결과적으로 나눈 사분면의 가장 우상단의 순서를 결과로 기록해서 div가 2가 되는 순간의 위치를 더한게 답
    int x = r / div;
    int y = c / div;

    // 사분면 별 첫 좌표 값 res에 저장하고 r,c 좌표 이동해서 재귀
    if (x == 0 && y == 0) {
        // 좌상단
        res += 0;
        func(r, c, div / 2);
    } else if (x == 0 && y == 1) {
        // 우상단
        res += div * div;
        func(r, c % div, div / 2);
    } else if (x == 1 && y == 0) {
        //좌하단
        res += div * div * 2;
        func(r % div, c, div / 2);
    } else if (x == 1 && y == 1) {
        // 우하단
        res += div * div * 3;
        func(r % div, c % div, div / 2);
    }
}

int main() {
    int r, c;
    cin >> n >> r >> c;
    // vector<vector<int> > v(pow(2, n), vector<int>(pow(2, n), 0));

    //
    int div = pow(2, n - 1);
    func(r, c, div);

    return 0;
}
