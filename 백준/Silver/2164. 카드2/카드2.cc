#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	while(q.size()>1){
		int s;
		q.pop();
		s=q.front();
		q.push(s);
		q.pop();
	}
	cout<<q.front();
}