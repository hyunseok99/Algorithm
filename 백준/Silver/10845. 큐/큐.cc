#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> Myqueue;
int main(void){
	int n;
	cin>>n;
	string str;
	while(n--){
		cin>>str;
		
		if(str=="push"){
			int k; cin>>k;
			Myqueue.push(k);
		}
		
		else if(str=="pop"){
			if(Myqueue.empty()) cout<<"-1"<<'\n';
			else {
				cout<<Myqueue.front()<<'\n';
				Myqueue.pop();
			}
		}
		
		else if(str=="size"){
			cout<<Myqueue.size()<<'\n';
		}
		
		else if(str=="empty"){
			cout<<Myqueue.empty()<<'\n';
		}
		
		else if(str=="front"){
			if(Myqueue.empty()) cout<<"-1"<<'\n';
			else cout<<Myqueue.front()<<'\n';
		}
		
		else if(str=="back"){
			if(Myqueue.empty()) cout<<"-1"<<'\n';
			else cout<<Myqueue.back()<<'\n';
		}
	}
	return 0;
}