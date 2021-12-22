#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string temp;
        cin>>temp;
        if(temp.length()%2){
            cout<<"NO"<<endl;
            continue;
        }
        bool done=true;
        for(int i=0;i<temp.length()/2;i++){
            if(temp[i]!=temp[i+temp.length()/2]){
                done=false;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(done) cout<<"YES"<<endl;
    }

}