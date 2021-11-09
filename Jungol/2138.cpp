#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
#define all(x) x.begin(),x.end()
using namespace std;

void setup(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n,m;

int dp[40000][32];

void solve(){
    dp[0][3]=1;
    dp[0][17]=1;
    for(int i=0;i<4*n-1;i++){
        for(int j=0;j<32;j++){
            if(j&2) dp[i+1][j>>1]=(dp[i+1][j>>1]+dp[i][j])%m;
            else if(i%4==2){
                if(!(j&2)) dp[i+1][(j|34)>>1]=(dp[i+1][(j|34)>>1]+dp[i][j])%m;
            }
            else{
                if(!(j&2)) dp[i+1][(j|34)>>1]=(dp[i+1][(j|34)>>1]+dp[i][j])%m;
                if(!(j&6)) dp[i+1][(j|6)>>1]=(dp[i+1][(j|6)>>1]+dp[i][j])%m;
            }
        }
    }
    cout<<dp[4*n-1][1];
}

int main(){
    cin>>n>>m;
    solve();

}
