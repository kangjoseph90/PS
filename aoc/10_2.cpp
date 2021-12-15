#include <bits/stdc++.h>

using namespace std;

#define int long long

map<char,int> key={{')',1},{']',2},{'}',3},{'>',4}};

map<char,char> rev={{')','('},{']','['},{'}','{'},{'>','<'}};
map<char,char> rev2={{'(',')'},{'[',']'},{'{','}'},{'<','>'}};

vector<int> ans;

int32_t main(){
    int t; cin>>t;
    while(t--){
        stack<char> s;
        string temp;
        cin>>temp;
        bool cor=false;
        for(auto ch:temp){
            if(ch==')'||ch==']'||ch=='}'||ch=='>'){
                if(s.empty()){
                    cor=true;
                    break;
                }
                else if(s.top()==rev[ch]) s.pop();
                else{
                    cor=true;
                    break;
                }
            }
            else s.push(ch);
        }
        if(cor||s.empty()) continue;
        int sum=0;
        while(!s.empty()){
            sum*=5;
            sum+=key[rev2[s.top()]];
            s.pop();
        }
        ans.push_back(sum);
        cout<<sum<<endl;
    }
    sort(ans.begin(),ans.end());
    cout<<ans[ans.size()/2]<<endl;;


}