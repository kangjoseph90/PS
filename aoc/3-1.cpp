#include <iostream>
#include <string>
#include <vector>
using namespace std;

int str2int(string s){
    int ret=0;
    for(int i=0;i<s.length();i++){
        ret=ret*2+s[i];
    }
    return ret;
}
int cnt[2][12];

int main(){
    string gamma,epsilon;
    string t;
    while(!cin.eof()){
        cin>>t;
        for(int i=0;i<t.length();i++){
            cnt[t[i]-'0'][i]++;
        }
    }
    for(int i=0;i<12;i++){
        gamma.push_back(cnt[0][i]>=cnt[1][i]?0:1);
        epsilon.push_back(1-gamma.back());
    }
    cout<<str2int(gamma)*str2int(epsilon)<<endl; 
}