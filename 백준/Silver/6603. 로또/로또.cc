#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[14];
int arr2[6];



void bt(int idx,int depth){
	if(depth==6){
		for(int i=0;i<6;i++) cout<<arr2[i]<<" ";
		cout<<"\n";
		return;
	}
	for(int i=idx;i<n;i++){
		arr2[depth]=arr[i];
		bt(i+1,depth+1);
	}
}

int main(){
	while(1){
	cin>>n;
	if(n==0) break;
	for(int i=0;i<n;i++){
		 cin>>arr[i];
	}
	bt(0,0);
	cout<<"\n";
	}
	return 0;
}