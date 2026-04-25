#include <iostream>
#include <string>
using namespace std;

int func(string A, string B){
    int cnt=0;
    for(int i=0; i<A.length(); i++){
        if(A[i] == B[i]) continue;
        else{
            int k = i+1;
            while(1){
                if(k== A.length()) return -1;
                if(A[i] == A[k]){
                    k++;
                }else{ break;}
            }
            A[k] = A[i];
            cnt = cnt + k - i;
            continue;
        }
    } 
    return cnt;
}

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        string A,B;
        cin>>A>>B;
        cout<<func(A,B)<<'\n';
    }
    return 0;
}