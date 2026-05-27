#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
typedef long long ll;

vector<string> convertToStr(vector<ll> & v);
bool isBinaryTree(int left, int right, string &partial);
// 10^15 ~= 2^60 
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    string str = "0111010";
    int ans = 0;
    // ex) 58: 111010 -> 0111010  포화 이진 트리 만들어야 함 
    vector<string> v = convertToStr(numbers);
    // for(auto i: v){
    //     cout << i << " ";
    // }
    // root를 기점으로 분리 했을 때 root가 1이어야 구성이 가능함 
    for(int i=0; i<v.size(); i++){
        bool flag = true;
        int start = 0;
        int end = v[i].size()-1;
        if(isBinaryTree(start, end, v[i])){
            answer.push_back(1);
        }else{
            answer.push_back(0);
        }
    }
    return answer;
}


// convert 10 -> 2 
vector<string> convertToStr(vector<ll> & v){
    vector<string> res;
    for(int i=0; i<v.size(); i++){
        string tmp;
        ll cur = v[i];
        while(cur > 0){
            
            ll quote = cur / 2;
            ll remain = cur % 2;
            tmp += to_string(remain);
            cur = quote;
        }
        
        // tmp의 size가 포화 이진트리 구성하게 0추가 // 1 3 7 15..  2^n-1 
        int len = tmp.size();
        int target_len = 1;
        while(target_len < len){
            target_len = (target_len + 1)*2 - 1;
        }
        for(int j=len; j<target_len; j++){
            tmp += "0";
        }
        // tmp reverse 
        reverse(tmp.begin(), tmp.end());
        res.push_back(tmp);
    }
    
    return res;
}

// 자식이 있는데 root = 1 이 아니면 불가 
bool isBinaryTree(int left, int right, string &partial){
    // 1. leaf면 true 종료 
    if(left >= right) return true;
    
    // 2. 자식이 있는데 root 0 여부  
    int root_idx = (left+right) / 2;
    int left_child_idx = (left + root_idx - 1) / 2;
    int right_child_idx = (root_idx + 1 + right) / 2;
    if(partial[root_idx] == '0'){
        if(partial[left_child_idx] == '1' || partial[right_child_idx] == '1'){
            return false;
        }
    }
    
    // 3. 가능하면 left children, right children 탐색
    if(!isBinaryTree(left, root_idx-1, partial)){
        return false;
    }
    if(!isBinaryTree(root_idx+1, right, partial)){
        return false;
    }
    return true;
}