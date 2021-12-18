#include <bits/stdc++.h>

using namespace std;


list<int> idx[500001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;
    int x=0;
    for(int i=0;i<t;i++){ 
        int a;
        cin>>a;
        if(a==1){
            int b;
            cin>>b;
            idx[b].push_back(x);
            x++;
        }
        if(a==2){
            int b,c;
            cin>>b>>c;
            idx[c].splice(idx[c].end(),idx[b]);
        }
    }
    vector<int> ans(x);
    for(int i=0;i<500001;i++){
        for(auto item:idx[i]){
            ans[item]=i;
        }
    }
    for(auto item:ans){
        cout<<item<<' ';
    }
}