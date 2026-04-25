#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
bool check[9];
vector<int> v;
vector<int> v2;

void bt(int idx){
	if(idx==m){
		for(auto &k:v2) cout<<k<<" ";
		cout<<"\n";
		return;
	}
	
	for(int i=0;i<n;i++){
		if(!check[i]){
		check[i]=1;
		v2.push_back(v[i]);
		bt(idx+1);
		v2.pop_back();
		check[i]=0;
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int j; cin>>j;
		v.push_back(j);
	}
	
	sort(v.begin(),v.end());
	
	bt(0);
	
	return 0;
}