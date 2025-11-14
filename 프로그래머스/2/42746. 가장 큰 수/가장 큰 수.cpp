#include <string>
#include <vector>
#include <queue>

using namespace std;

struct comp{
    bool operator()(int &a, int &b){
        string first = to_string(a) + to_string(b);
        string second = to_string(b) + to_string(a);
        return first < second;
    }
};

priority_queue<int,vector<int>, comp> pq;
string solution(vector<int> numbers) {
    string answer = "";
    for(int i=0; i<numbers.size(); i++){
        pq.push(numbers[i]);
    }
    
    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        answer += to_string(cur);
    }
    
    if(answer.size() > 1 && answer[0] == '0'){
        answer = "0";
    }
    return answer;
}