#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a; cin>>a; 
        v.push_back(a);
    }
    stack<int> s;
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        while(!s.empty()){
            if(s.top()>v[i]) break;
            s.pop();
        }
        if(s.empty()) ans[i]=-1;
        else ans[i]=s.top();
        s.push(v[i]);
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<' ';

}