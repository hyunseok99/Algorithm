#include <iostream>
using namespace std;

int A[101];
int B[101];
int DP[101][100001];

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>A[i]>>B[i];
	}
	for(int i=1;i<=n;i++ ){
		for(int j=1;j<=k;j++){
			if(A[i]<=j) DP[i][j]=max(DP[i-1][j],DP[i-1][j-A[i]]+B[i]);
			else DP[i][j]=DP[i-1][j];
		}
	}
	cout<<DP[n][k];
	return 0;
}