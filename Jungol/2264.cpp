#include <iostream>
using namespace std;

#define mod 1000000003


int dp[1001][1001];

int n,k;

int main(){
    for(int i=1;i<1001;i++){
        for(int j=0;j<=i;j++){
            if(j==0||j==i) dp[i][j]=1;
            else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }
    cin>>n>>k;
    int ans=dp[n-k+1][k];
    if(k>=2) ans-=dp[n-k-1][k-2];
    ans=(ans+mod)%mod;
    if(k>n/2) ans=0;
    cout<<ans;
}