#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int mod=1e9+7;

int n,k;

int pow(int base,int x){
    if(x==0) return 1;
    int t=pow(base,x/2);
    if(x%2) return (((t*t)%mod)*base)%mod;
    return (t*t)%mod;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    int ans=1;
    for(int i=0;i<k;i++){
        ans=(ans*(n-i))%mod;
        ans=(ans*pow(i+1,mod-2))%mod;
    }
    cout<<ans<<endl;
}