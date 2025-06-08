#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void doSort(vector<int> array, vector<int> &answer, vector<vector<int>> commands){
    vector<int> tmp = array;
    for(int i=0; i<commands.size(); i++) {
        vector<int> selected;
        for(int j=commands[i][0]-1; j < commands[i][1]; j++){
            selected.push_back(tmp[j]);
        }
        sort(selected.begin(), selected.end());
        answer.push_back(selected[commands[i][2]-1]);
    }
    return;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    doSort(array, answer, commands);

    return answer;
}