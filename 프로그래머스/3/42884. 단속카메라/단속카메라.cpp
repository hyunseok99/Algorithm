#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

int res = 0;

// a1  a2
//     b1  b2
//         c1  c2
//             d1  d2

// 위의 순서처럼 진입 지점으로 부터 정렬 -> 이후 차량의 진입 지점이 지나지 않으면 새로 설치10 

// -> 특정 구간 사이의 값에서 가장 많이 겹쳐있는 곳에 설치 -> 지나는 차들 제외 -> 남은 차들끼리 반복
// -> 이  과정에서 더이상 차 x 그 때 단속 카메라 수가 최소 




// 복잡도 O(n)
void setCamera(vector<pair<int,int>> &v){
    // 끝 지점 -> 다음 차량의 시작 보다 크면 -> cctv설치 및 갱신
    res = 1; // 처음에 설치 
    int start = v[0].second;
    for(int i=1; i<v.size(); i++){
        if(v[i].first <= start) continue;
        // 카메라 설치 및 범위 갱신
        res++;
        start = v[i].second; 
    }
}

// 입력받은 루트 정렬 -> r[i][0], r[i][1] 에대해서 i에 따른 지나는 경우 중 최대 값
// 가능한 값들: 위의 끝점 
int solution(vector<vector<int>> routes) {
    
    // 루트 정렬 : a~b, a < b
    vector<pair<int,int>> v;
    for(int i=0; i< routes.size(); i++){
        int a = routes[i][0];
        int b = routes[i][1];
        if(a > b) swap(a, b);
        v.push_back({a, b});
    }
    
    sort(v.begin(), v.end(), [](pair<int,int> &a, pair<int, int> &b){ return a.second < b.second;});
    
    
    setCamera(v);
    
    return res;
}