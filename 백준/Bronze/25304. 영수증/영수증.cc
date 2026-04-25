#include <iostream>
using namespace std;

int n,x,a,b,res;
int main(){
    cin>>x>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        res+=a*b;
    }
    if(x==res) cout<<"Yes";
    else cout<<"No";
    return 0;
}