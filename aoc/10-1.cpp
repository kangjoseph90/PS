#include <bits/stdc++.h>

using namespace std;

map<char,int> key={{')',3},{']',57},{'}',1197},{'>',25137}};

map<char,char> rev={{')','('},{']','['},{'}','{'},{'>','<'}};

int ans=0;

int main(){
    int t; cin>>t;
    while(t--){
        stack<char> s;
        string temp;
        cin>>temp;
        for(auto ch:temp){
            if(ch==')'||ch==']'||ch=='}'||ch=='>'){
                if(s.empty()){
                    ans+=key[ch];
                    break;
                }
                else if(s.top()==rev[ch]) s.pop();
                else{
                    ans+=key[ch];
                    break;
                }
            }
            else s.push(ch);
        }
    }
    cout<<ans<<endl;
}