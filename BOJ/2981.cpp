#include <bits/stdc++.h>
using namespace std;
#define int long long 


int n;

vector<int> v;

int gcd(int a,int b){
    if(a%b) return gcd(b,a%b);
    return b;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int now=v[1]-v[0];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            now=gcd(now,v[j]-v[i]);
        }
    }
    vector<int> d;
    for(int i=1;i*i<=now;i++){
        if(i*i==now) d.push_back(i);
        else if(now%i==0){
            d.push_back(i);
            d.push_back(now/i);
        }
    }
    sort(d.begin(),d.end());
    for(auto item:d){
        if(item==1) continue;
        cout<<item<<' ';
    }
}