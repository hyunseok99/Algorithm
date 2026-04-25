#include <iostream>
using namespace std;

int n,k,ans;
int a[10];

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>=0;i--){
		ans+=k/a[i];
		k%=a[i];
	}
	cout<<ans;
}