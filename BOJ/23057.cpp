#include <bits/stdc++.h>

using namespace std;

#define int long long

int n,m;
vector<int> v;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
        m+=a;
    }
    sort(v.begin(),v.end());
}