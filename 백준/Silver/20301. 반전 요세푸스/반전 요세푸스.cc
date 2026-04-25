#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;

int main(){
	int n,k,m;
	cin>>n>>k>>m;
	int mode=0;
	int ktmp=0;
	for(int i=1;i<=n;i++){
		dq.push_back(i);
	}
	while(!dq.empty()){
		if(mode==0){
			int tmp=k-1;
			while(tmp--){
				dq.push_back(dq.front());
				dq.pop_front();
			}
			cout<<dq.front()<<'\n';
			dq.pop_front();
			ktmp++;
			if(ktmp==m){
				ktmp=0;
				mode=!mode;
			}
		}
		else if(mode==1){
			int tmp=k-1;
			while(tmp--){
				dq.push_front(dq.back());
				dq.pop_back();
			}
			cout<<dq.back()<<'\n';
			dq.pop_back();
			ktmp++;
			if(ktmp==m){
				ktmp=0;
				mode=!mode;
			}
		}
	}
	return 0;
}