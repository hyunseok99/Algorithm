#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>
#include <queue>
using namespace std;

struct compare1{
    int operator()(pair<int,int>& o1, pair<int,int>& o2){
        if(o1.second == o2.second) return o1.first > o2.first;
        return o1.second < o2.second;
    }
};

struct sing{
    string genre;
    int cnt;
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare1> songs; 
};



struct compare2{
    bool operator()(sing& o1, sing& o2){
        return o1.cnt < o2.cnt;
    }
};



vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, sing> my_map;
    priority_queue<sing, vector<sing>, compare2> res;
    for(int i=0; i< genres.size(); i++){
        if(my_map.find(genres[i]) != my_map.end()){
            sing tmp = my_map[genres[i]];
            tmp.cnt += plays[i];
            tmp.songs.push({i,plays[i]});
            my_map[genres[i]] = tmp;
        }else{
            sing tmp;
            tmp.genre = genres[i];
            tmp.cnt = plays[i];
            tmp.songs.push({i,plays[i]});
            my_map[genres[i]] = tmp;
        }
    }
    
    for(auto v: my_map){
        sing tmp = v.second;
        res.push(tmp);
    }
    
    while(!res.empty()){
        sing tmp = res.top();
        res.pop();
        int idx = 0;
        while(!tmp.songs.empty()){
            if(idx == 2) break;
            answer.push_back(tmp.songs.top().first);
            //cout<< tmp.songs.top().first <<" "<<tmp.songs.top().second<<"\n";
            tmp.songs.pop();
            idx++;
        }
    }
   
    
    return answer;
}