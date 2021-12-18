#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        int cnt=0;
        string str;
        cin>>str;
        for(auto ch:str){
            if(ch=='N') cnt++;
        }
        if(cnt==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}