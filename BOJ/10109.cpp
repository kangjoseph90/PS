#include <bits/stdc++.h>

using namespace std;

#define min3(x,y,z) min(x,min(y,z))

int dp[2000][2000];

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c; cin>>c;
            if(c=='#') dp[i][j]=1;
        }
    }
    int ans=0;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(!dp[i][j]) continue;
            if(i<n-1&&j>0&&j<n-1){
                dp[i][j]+=min3(dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]);
            }
            ans+=dp[i][j];
        }
    }
    cout<<ans<<'\n';

}