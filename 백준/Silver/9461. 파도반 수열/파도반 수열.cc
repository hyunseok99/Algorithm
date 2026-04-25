#include <iostream>
using namespace std;

int arr[101];
long long p[101];

int main(){
	int n; cin>>n;
	p[1]=1; p[2]=1; p[3]=1; p[4]=2 ;p[5]=2;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		for(int j=6;j<=arr[i];j++){
		p[j]=p[j-1]+p[j-5];
		}
	}
	for(int i=1;i<=n;i++){
		cout<<p[arr[i]]<<'\n';
	}
}