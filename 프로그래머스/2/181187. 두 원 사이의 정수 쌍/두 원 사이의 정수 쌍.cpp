#include <string>
#include <vector>
#include <cmath>
#include <iostream>
typedef long long ll;

using namespace std;

ll axis = 0;
ll res = 0;
long long solution(int r1, int r2) {
    // r1 <= a+b <= r2 
    // 4*res -> (r2, 0) ~ (0, r2-1) 
    for(int x=1; x<=r2; x++){
        ll max_y = floor(sqrt(pow(r2,2)-pow(x,2)));
        ll min_y = 0;
        if(x < r1){
            min_y = ceil(sqrt(pow(r1,2) - pow(x,2)));
        }
        res += (max_y - min_y + 1);
    }
    
    return res*4;
}

