#include <iostream>
#include <string>
using namespace std;

int main(){
    string c;
    string alpha="abcdefghijklmnopqrstuvwxyz";
    cin>>c;
    for(int i=0;i<alpha.length();i++){
        cout<<(int)c.find(alpha[i])<<" ";
    }
    return 0;
}