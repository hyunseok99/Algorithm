#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string book[1001];
int main(void){
   ios_base::sync_with_stdio(NULL); cin.tie(NULL);
    int n;
        cin>>n;
	for(int i=0;i<n;i++){
		cin>>book[i];
	}
	int max=0;
	int num=0;
	string temp=book[0];
	string end;
	sort(book,book+n);
	for(int i=0;i<n;i++){
		if(book[i]==temp) num++;
		else{
			if(max<num){
				max=num;
				end=temp;
			}
			temp=book[i];
			num=1;
		}
	}
	if(max<num) end=temp;
	
	cout<<end<<'\n';
	return 0;
}