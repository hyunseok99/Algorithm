#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int check[9];
vector<int> v;
vector<int> v2;
int cnt;
int num;
int kg=500;

void bt(){
	if(v2.size()==n){
		
		cnt=0;
		for(int k=0;k<n;k++){
			if(kg+v2[k]-m<500) {
				cnt++;
			}
			kg=kg+v2[k]-m;
		}
		kg=500;
		if(cnt==0) num++;
		return;
	}
	for(int i=0;i<n;i++){
		if(!check[i]){
		check[i]=1;
		v2.push_back(v[i]);
		bt();
		check[i]=0;
		v2.pop_back();
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int j; cin>>j;
		v.push_back(j);
	}
	bt();
	cout<<num;
	
}