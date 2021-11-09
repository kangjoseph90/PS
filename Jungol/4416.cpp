#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX(x,y) (x>y?x:y)

int board[200][200];

int dp[200][200];

int n,m;

int solve(){
    dp[0][0]=board[0][0];
    for(int i=1;i<m;i++) dp[0][i]=dp[0][i-1]+board[0][i];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(j==0){
                dp[i][j]=dp[i-1][j]+board[i][j];
            }
            else dp[i][j]=MAX(dp[i-1][j],dp[i][j-1])+board[i][j];
        }
    }
    return dp[n-1][m-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) cin>>board[i][j];
    cout<<solve();
}