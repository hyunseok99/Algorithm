#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 1번: 12345 반복
// 2번: 21 23 24 25 반복
// 3번: 33 11 22 44 55 반복

struct human{
    int num,score;
    human(int a, int b){
        this->num = a;
        this->score = b;
    }
};

vector<int> getScore(vector<int> &answers){
    // 0,1,2
    vector<int> score(3, 0);
    vector<vector<int>> person(3);
    person[0] = {1, 2, 3, 4, 5};
    person[1] = {2, 1, 2, 3, 2, 4, 2, 5};
    person[2] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i=0; i<answers.size(); i++){
        int first = i % (int)person[0].size();
        int second = i % (int)person[1].size();
        int third = i% (int)person[2].size();
        
        if(answers[i] == person[0][first]){
            score[0]+=1;;
        }
        if(answers[i] == person[1][second]){
            score[1]+=1;
        }
        if(answers[i] == person[2][third]){
            score[2]+=1;
        }
    }
    
    human human1(1, score[0]);
    human human2(2, score[1]);
    human human3(3, score[2]);
    vector<human> v = {human1, human2, human3};
    sort(v.begin(), v.end(), [](human &a, human &b){
        if(a.score == b.score){
            return a.num < b.num;
        }else{
            return a.score > b.score;
        }
    });
    
    vector<int> answer;
    int val = v[0].score;
    answer.push_back(v[0].num);
    for(int i=1; i<3; i++){
        if(v[i].score != val) continue;
        answer.push_back(v[i].num);
    }
    return answer;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    answer = getScore(answers);
    return answer;
}