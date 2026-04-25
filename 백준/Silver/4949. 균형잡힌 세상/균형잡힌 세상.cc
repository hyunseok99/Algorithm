#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	while(1){
		string str;
		getline(cin,str);
		stack<char> s;
		
		if(str=="."){
			break;
		}
		
		bool check=true;
		for(int i=0;i<str.length();i++){
			if(str[i]=='(' || str[i]=='['){
				s.push(str[i]);
			}
			else if(str[i]==')'){
				if(s.empty()||s.top()=='[') {
					check=false;
					break;
				}
				else if(s.top()=='(' ) {
					s.pop();
				}
			}
			else if(str[i]==']'){
				if(s.empty()||s.top()=='(') {
					check=false;
					break;
				}
				else if(s.top()=='[') {
					s.pop();
				}
			}	
		}
		if(s.empty() && check) cout<<"yes"<<'\n';
		else cout<<"no"<<'\n';
	}
	return 0;
}