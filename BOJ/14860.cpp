#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod=1e9+7;

int n,m;

int ans=1;

int pow(int base,int x){
    if(x==0) return 1;
    if(x%2){
        int temp=pow(base,x/2);
        return (((temp*temp)%mod)*base)%mod;
    }
    else{
        int temp=pow(base,x/2);
        return (temp*temp)%mod;
    }
}

void f(int p){
    int sum=0;
    for(int j=p;j<=max(n,m);j*=p){
        sum+=(n/j)*(m/j);
    }
    //cout<<p<<' '<<sum<<endl;
    ans*=pow(p,sum);
    ans%=mod;
}

int32_t main(){
    cin>>n>>m;
    vector<bool> check(15000001);
    int i;
    for(i=2;i<=max(n,m);i++){
        if(!check[i]){
            f(i);
            for(int j=2;i*j<=max(n,m);j++){
                check[j*i]=true;
            }
        }
    }
    cout<<ans<<endl;
       
}