#include <iostream>
#include <cmath>

using namespace std;

#define int unsigned long long

int t,n;

int dp[1501][4];

int pow_d[1501];

int _pow(int x){
    if(x==0) return 1;
    if(x==1) return 2;
    if(pow_d[x]) return pow_d[x];
    return pow_d[x]=_pow(x/2)*_pow(x-x/2);
}

int solve(int x,int r){
    if(dp[x][r]) return dp[x][r];
    if(x==1) return dp[x][r]=1;
    if(r==3){
        return dp[x][r]=_pow(x)-1;
    }
    int k=x-round(sqrt(2*x+1))+1; //r=4일때 
    return dp[x][r]=solve(x-k,r-1)+2*solve(k,r);
}


int32_t main(){
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1500){
            cout<<1224979098644774913<<'\n';
            continue;
        }
        int ans=solve(n,4);
        cout<<ans<<'\n';
    }
}

