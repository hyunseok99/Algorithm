#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
int arr[9];
int ans[9];
int check[9];
int k;
void bt(int idx){
	if(idx==m){
		for(int i=0;i<m;i++) cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}	
	int k=0;
	for(int i=0;i<n;i++){
		if(!check[i]&& arr[i]!=k){
			ans[idx]=arr[i];
			k=ans[idx];
			check[i]=1;
			bt(idx+1);
			check[i]=0;
		}
	}
	
	
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	bt(0);
	return 0;
}