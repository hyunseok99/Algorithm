#include <iostream>
#include <vector>
using namespace std;

int n,m;
bool visited[9];
vector<int> v;

void bt(){
	if(v.size()==m){
		for(auto &k:v) cout<<k<<" ";
		cout<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]) {
		
		visited[i]=1;
		v.push_back(i);
		bt();
		visited[i]=0;
		v.pop_back();
		}
	}
}

int main(){
	cin>>n>>m;
	bt();
	return 0;	
}