#include <iostream>
#include <stack>
using namespace std;

stack<int> st;

int main(){
	int k;
	int sum=0;
	cin>>k;
	for(int i=0;i<k;i++){
		int n; cin>>n;
		if(n==0 && st.empty()==0 ){
			st.pop();
		}
		else if(n!=0) st.push(n);
	}
	while(st.size()){
		sum+=st.top();
		st.pop();
	}
	cout<<sum;
}