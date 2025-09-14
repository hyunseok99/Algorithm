#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

// 우선순위: 작업 소요시간 짧, 요청 시각 빠른 것, 작업의 번호가 작은 것 

class disk{
    public: int num, request_time, doing_time;
    disk(int a, int b, int c){
        this->num = a;
        this->request_time = b;
        this->doing_time = c;
    }
};

struct diskComp{
    bool operator()(disk& a, disk& b){
        if(a.doing_time == b.doing_time){
            if(a.request_time == b.request_time){
                return a.num > b.num;
            }else{
                return a.request_time > b.request_time;
            }
        }else{
            return a.doing_time > b.doing_time;
        }
    }
};

// return: turnaround time 
int doController(vector<disk> &disks){
    int total_jobs = disks.size();
    priority_queue<disk, vector<disk>, diskComp> pq;
    // 첫 작업 시작부터 끝 사이 시간에 직업 요청 이루어지면 우선순위 큐에 삽입 
    int idx = 0;
    int cur_time = 0;
    int total_time = 0; 
    int done_jobs = 0;
    // 모든 작업을 완료하기 전까지 반복 
    while(done_jobs < total_jobs){
        // 현재 시간 이전에 요청된 작업 삽입
        while(idx < total_jobs && cur_time >= disks[idx].request_time){
            pq.push(disks[idx]);
            idx++;
        }
        
        // 다음 작업이 들어기까지 시간이 필요할 수 있음 [0, 5] -> [10, 3] 유휴시간 처리 필요
        if(pq.empty()){
            //현재 시간을 해당 작업 요청시간으로 점프
            cur_time = disks[idx].request_time;
            continue;
        }
        // 다음 작업 있는 경우 작업 개시
        
        disk cur_job = pq.top();
        pq.pop();
        
        // 작업 종료 시간 = 현재시간 + 작업시간
        cur_time += cur_job.doing_time;  
        // 총 소요시간
        total_time += cur_time - cur_job.request_time;
        done_jobs++;
        
    }
    return (total_time / total_jobs);   
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    // 요청 시간 기준 정렬 필요, 이때의 idx도 유지 필요
    vector<disk> disks;
    for(int i=0; i<jobs.size(); i++){
        disk tmp(i,jobs[i][0], jobs[i][1]);
        disks.push_back(tmp);
    }
    sort(disks.begin(), disks.end(), [](disk &a, disk& b){
        return a.request_time < b.request_time; 
    });
    answer = doController(disks);
    return answer;
}