#include <iostream>
using namespace std;

long long dp[91];

int main(){
	int n; cin>>n;
	long long ans;
	dp[0]=1; dp[1]=1;
	for(int i=2;i<=n;i++){
		ans=0;	
		for(int j=0;j<i;j++){
			ans+=dp[j]*dp[i-j-1];
		}	
		dp[i]=ans;
	}
	cout<<dp[n];
}