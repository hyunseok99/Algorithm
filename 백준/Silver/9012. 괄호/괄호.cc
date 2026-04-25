#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	int n;
	cin>>n;
	string str;
	while(n--){
		stack<int> Mystack;
		int check=0;
		cin>>str;
		for(auto &c:str){
			if(c=='(') Mystack.push(1);
			else{
				if(Mystack.empty()) {
					check=1;
					break;
				}
				else Mystack.pop();
			}
		}
		if(check==0 && Mystack.empty()) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
	return 0;
}