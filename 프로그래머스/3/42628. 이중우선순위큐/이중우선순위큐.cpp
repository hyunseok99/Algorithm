#include <string>
#include <vector>
#include <queue>
#include <regex>
#include <cmath>
#include <unordered_map>
#include <iostream>
using namespace std;



int total = 0;

void doOperation(string op, string str_val, priority_queue<int,vector<int>, greater<int>> &pq_min, priority_queue<int> &pq_max, unordered_map<int,int> &my_map){
    // operation 판독, val로 삽입,삭제 판독 
    int val =  stoi(str_val);
    
    if(op == "I"){
        // 삽입
        pq_min.push(val);
        pq_max.push(val);
        my_map[val] +=1;
        total++;
    }else{
        if(val > 0){
            // 이미 삭제 데이터 제거 후 -> 최대값 삭제
            while(!pq_max.empty() && my_map[pq_max.top()] == 0){
                pq_max.pop();
            }
            if(!pq_max.empty()){
                my_map[pq_max.top()] -= 1;
                pq_max.pop();
                total--;
            }
        }else{
            // 최솟값 삭제 
            while(!pq_min.empty() && my_map[pq_min.top()] == 0){
                pq_min.pop();
            }
            if(!pq_min.empty()){
                my_map[pq_min.top()] -= 1;
                pq_min.pop();
                total--;
            }
        }
    }
}

vector<int> transOperations(vector<string> &operations){
    // total 초기화
    total = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq_min;
    priority_queue<int> pq_max;

    unordered_map<int,int> my_map; // 실제 데이터의 갯수 
    
    regex re(" ");
    for(int i=0; i<operations.size(); i++){
        string str = operations[i];
        // split
        sregex_token_iterator start(str.begin(), str.end(), re, -1);
        sregex_token_iterator end;
        
        vector<string> v;
        for(; start != end; start++){
            v.push_back(*start);
        }
        
        doOperation(v[0], v[1], pq_min, pq_max, my_map);
    }
    
    // 모든 작업후 pq_min = deleted_pq_max , pq_max = deleted_pq_min
    vector<int> answer = {0, 0};
    
    // 남아있는 경우 
    if(total > 0){
        // 유령 데이터 제거 
        while(!pq_max.empty() && my_map[pq_max.top()] == 0){
            pq_max.pop();
        }
        while(!pq_min.empty() && my_map[pq_min.top()] == 0){
            pq_min.pop();
        }
        
        answer[0] = pq_max.top();
        answer[1] = pq_min.top();
    }
    
    return answer;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    answer = transOperations(operations);
    return answer;
}