#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int l,c;
vector<char> v;
vector<char> v2;
//97,101,105,111,117 

bool check(){
	int k=0;
	for(int i=0;i<l;i++){
		if(v2[i]==97 ||v2[i]==101 ||v2[i]==105 ||v2[i]==111 ||v2[i]==117)
		k++;
	}
	if(k>0 && l-k>1) return true;
	else return false;
}

void bt(int idx){
	if((int)v2.size()==l){
		if(check()){
			for(int j=0;j<l;j++){
				cout<<v2[j];
			}
			cout<<"\n";
		}
		return;
	}
	for(int i=idx;i<c;i++){
		v2.push_back(v[i]);
		bt(i+1);
		v2.pop_back();
	}
}

int main(){
	cin>>l>>c;
	for(int i=0;i<c;i++){
		char chr;
		cin>>chr;
		v.push_back(chr);
	}
	sort(v.begin(),v.end());
	bt(0);
}