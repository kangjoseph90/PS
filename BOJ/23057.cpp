#include <bits/stdc++.h>
using namespace std;

set<int> s;

int n,m;

vector<int> v;

void solve(int idx,int sum){
    if(idx==n){
        if(sum)
            s.insert(sum);
        return;
    }
    solve(idx+1,sum+v[idx]);
    solve(idx+1,sum);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        m+=v[i];
    } 
    solve(0,0);
    //cout<<m<<endl;
    cout<<m-s.size();
}