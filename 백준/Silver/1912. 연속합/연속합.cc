#include <iostream>
using namespace std;

int n;
int som;
int arr[100001];
int dp[100001];



int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	dp[0]=arr[0];
	som=dp[0];
	for(int i=1;i<n;i++){
		dp[i]=arr[i];
		if(dp[i]<dp[i-1]+arr[i])
		dp[i]=dp[i-1]+arr[i];
		som=max(som,dp[i]);
	}
cout<<som;
	
return 0;	
}