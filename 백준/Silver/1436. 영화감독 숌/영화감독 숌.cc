#include <iostream>
using namespace std;

int n,cnt,ans,tmp;

int main(){
    cin>>n;
    
    while(cnt!=n){
        ans++;
        tmp = ans;
        
        while(tmp!=0){
            if(tmp%1000 == 666){
                cnt++;
                break;
            }
            else tmp /=10;
        }
    }
    cout<<ans;
}