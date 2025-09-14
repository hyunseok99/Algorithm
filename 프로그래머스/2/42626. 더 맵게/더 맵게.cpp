#include <string>
#include <vector>
#include <queue>
using namespace std;

struct comp{
    bool operator()(int &a, int &b){
        return a > b;
    }
};

int doMix(vector<int> &scoville, int K ){
    int res = 0;
    
    priority_queue<int, vector<int>, comp> pq;
    
    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    bool flag = false;
    while(pq.size() >= 2){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        if(first >= K){ 
            flag = true;
            break;
        }
        int newScoville = first + 2*second;
        pq.push(newScoville);
        res++;
    }
    
    if(!flag){
        if(pq.top() < K) res = -1;
    }
    
    return res;
}

int solution(vector<int> scoville, int K) {
    int answer = doMix(scoville, K);
    return answer;
}