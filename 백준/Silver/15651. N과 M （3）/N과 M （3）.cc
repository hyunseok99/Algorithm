#include<iostream>
#include<vector>
using namespace std;

int n,m;
bool check[8];
vector<int> v;

void bt(){
	if(v.size()==m){
		for(auto &k:v) cout<<k<<" ";
		cout<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(!check[i])
		check[i]=1;
		v.push_back(i);
		bt();
		v.pop_back();
		check[i]=0;
	}
}

int main(){
	cin>>n>>m;
	bt();
	return 0;
}