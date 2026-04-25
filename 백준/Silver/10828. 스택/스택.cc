#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> Mystack;

int main(){
	int n;
	cin>>n;
	string str;
	while(n--){
		cin>>str;
		if(str=="push"){
			int k; cin>>k;
			Mystack.push(k);
		}
		else if(str=="pop"){
			if(Mystack.empty())
			cout<<"-1"<<'\n';
			
			else {
				cout<<Mystack.top()<<'\n';
				Mystack.pop();
			}
		}
		else if(str=="size"){
			cout<<Mystack.size()<<'\n';
		}
		else if(str=="empty"){
			cout<<Mystack.empty()<<'\n';
		}
		else if(str=="top"){
			if(Mystack.empty()) cout<<"-1"<<'\n';
			else cout<<Mystack.top()<<'\n';
		}
		
	}
	return 0;
}