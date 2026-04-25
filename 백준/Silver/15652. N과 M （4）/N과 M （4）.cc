#include<iostream>
#include<vector>
using namespace std;

int n,m;
bool check[9];
vector<int> v;

void bt(int num){
	if(v.size()==m){
		for(auto &k:v) cout<<k<<" ";
		cout<<"\n";
		return;
	}
	for(int i=num;i<=n;i++){
		if(!check[i])
		check[i]=1;
		v.push_back(i);
		bt(i);
		v.pop_back();
		check[i]=0;
	}
}

int main(){
	cin>>n>>m;
	bt(1);
	return 0;
}