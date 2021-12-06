#include <bits/stdc++.h>

using namespace std;

#define int long long

int dp[9][257];

int solve(int cnt,int day){
    if(dp[cnt][day]) return dp[cnt][day];
    if(day==256) return dp[cnt][day]=1;
    int ret=0;
    if(cnt==0){
        ret+=solve(6,day+1)+solve(8,day+1);
    }
    else ret+=solve(cnt-1,day+1);
    return dp[cnt][day]=ret;
}

int32_t main(){
    int t;
    cin>>t;
    int ans=0;
    while(t--){
        int n;
        cin>>n;
        ans+=solve(n,0);
    }
    cout<<ans;

}