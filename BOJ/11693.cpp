#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int mod=(int)1e9+7;

int n,m;


map<int,int> p;

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
    cin>>n>>m;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            n/=i;
            p[i]++;
        }
    }
    p[n]++;
    int ans=1;
    for(auto item:p){  //페르마 소정리
        if(item.first==1) continue;
        int now=(pow(item.first,item.second*m+1)-1+mod)%mod;
        now=(now*pow(item.first-1,mod-2))%mod;
        ans=(ans*now)%mod;
    }
    cout<<ans<<endl;
}