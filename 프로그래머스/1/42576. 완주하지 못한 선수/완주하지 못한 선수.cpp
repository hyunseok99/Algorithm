#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
//     unordered_map<string, int> my_map;
//     string answer = "";

//     // 참여자 map에 저장 
//     for(int i=0; i<participant.size(); i++){
//         my_map[participant[i]]++;
//     }
    
//     // 완주자 int--;
//     for(int i=0; i<completion.size(); i++){
//         my_map[completion[i]]--;
//     }
    
//     for(auto x: my_map){
//         if(x.second == 1 ) answer = x.first;
//     }
    
    unordered_map<string, int> my_map;
    
    for(int i=0; i<participant.size(); i++){
        auto it = my_map.find(participant[i]); 
        if( it != my_map.end()){
            it->second++;
        }else{
            my_map.insert({participant[i], 1});
        }
    }
    
    for(int i=0; i<completion.size(); i++){
        auto it = my_map.find(completion[i]);
        if(it != my_map.end()){
            it->second--;
        }
    }
    string answer = "";
    for(auto it: my_map){
        if(it.second != 0){
            answer = it.first;
            break;
        }
    }
    return answer;
}

