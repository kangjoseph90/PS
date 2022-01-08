#include <bits/stdc++.h>

using namespace std;

#define int long long 

int32_t main(){
    vector<int> v={0};
    for(int i=1;i*i<INT_MAX;i++){
        v.push_back(i*i);
        v.push_back(i*(i+1));
    }
    int t;
    cin>>t;
    while(t--){
        int x,y; cin>>x>>y;
        cout<<(lower_bound(v.begin(),v.end(),y-x)-v.begin())<<endl;
    }

}