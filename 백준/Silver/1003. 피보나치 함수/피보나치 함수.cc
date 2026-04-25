#include <iostream>
using namespace std;

int a[41];
int b[41];

int main(){
	int t;
	cin>>t;
	a[0]=1; b[1]=1;
	for(int i=2;i<41;i++){
		a[i]=a[i-1]+a[i-2];
		b[i]=b[i-1]+b[i-2];
	}
	for(int i=0;i<t;i++){
		int c; cin>>c;
		cout<<a[c]<<" "<<b[c]<<"\n";
	}
	return 0;
}