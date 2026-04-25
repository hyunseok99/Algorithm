#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,cnt;
bool check1[14];
bool check2[27];
bool check3[27];	

void bt(int x){
	if(x==n){
		cnt++;
		return ;
	} 
	for(int y=0;y<n;y++){
		if((check1[y] || check2[x+y]|| check3[x-y+n-1])) continue; //queen role x
		check1[y]=1;	//check series=1
		check2[x+y]=1;
		check3[x-y+n-1]=1;
		bt(x+1);
		
		check1[y]=0;	//check series=0
		check2[x+y]=0;
		check3[x-y+n-1]=0;
	}				
}




int main(){
	cin>>n;
	bt(0);
	cout<<cnt;
}