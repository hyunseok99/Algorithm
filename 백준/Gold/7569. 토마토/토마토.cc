#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m,h,res=0;

vector<vector<vector<int>>> v;
queue<pair<pair<int,int>,int>> q;
queue<pair<pair<int,int>,int>> q2;

int dx[] = {-1,1,0,0,0,0};
int dy[] = {0,0,-1,1,0,0};
int dz[] = {0,0,0,0,-1,1};

void run(int x, int y, int z){
    for(int i=0; i<6; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nz = z + dz[i];
        if(nx>=0 && ny>=0 && nz>=0 && nx<n && ny <m && nz < h && v[nx][ny][nz] == 0){
            v[nx][ny][nz] = 1;
            q2.push({{nx,ny},nz});
        }
    }
}

int main(){
    cin >> m >> n >> h;
    
    v.resize(n, vector<vector<int>>(m, vector<int> (h)));

    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin>>v[j][k][i];
                if(v[j][k][i] == 1){
                    q.push({{j,k},i});
                }
            }
        }
    }
    
    while(!q.empty()){
        pair<pair<int,int>,int> tmp = q.front();
        q.pop();
        run(tmp.first.first, tmp.first.second, tmp.second);
        if(q.empty()){
            res++;
            while(!q2.empty()){
                q.push(q2.front());
                q2.pop();
            }
        }
    }
    
     for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(v[j][k][i] == 0){
                    cout<< -1;
                    return 0;
                }
            }
        }
    }
    cout<< --res;
    return 0;
}