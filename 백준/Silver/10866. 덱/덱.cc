#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<int> Mydeque;

int main(){
	int n;
	cin>>n;
	string str;
	while(n--){
		cin>>str;
		if(str=="push_front"){
			int k; cin>>k;
			Mydeque.push_front(k);
		}
		
		else if(str=="push_back"){
			int k;cin>>k;
			Mydeque.push_back(k);
		}
		
		else if(str=="pop_front"){
			if(Mydeque.empty()) cout<<"-1"<<'\n';
			else {
				cout<<Mydeque.front()<<'\n';
				Mydeque.pop_front();
			}	
		}
		
		else if(str=="pop_back"){
			if(Mydeque.empty()) cout<<"-1"<<'\n';
			else{
				cout<<Mydeque.back()<<'\n';
				Mydeque.pop_back();
			}	
		}
		
		else if(str=="size"){
			cout<<Mydeque.size()<<'\n';
		}
		
		else if(str=="empty"){
			cout<<Mydeque.empty()<<'\n';
		}
		
		else if(str=="front"){
			if(Mydeque.empty()) cout<<"-1"<<'\n';
			else cout<<Mydeque.front()<<'\n';
		}
		
		else if(str=="back"){
			if(Mydeque.empty()) cout<<"-1"<<'\n';
			else cout<<Mydeque.back()<<'\n';
		}
	}
}