#include<iostream>
using namespace std;

int n,m,sum,cnt;
int arr[21];

void bt(int idx){
	if(idx==n) return;
	sum+=arr[idx];
	if(sum==m) cnt++;
	bt(idx+1);
	sum-=arr[idx];
	bt(idx+1);
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	bt(0);
	cout<<cnt;
	return 0;
}