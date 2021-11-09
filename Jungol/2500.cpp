#include <iostream>
#include <vector>

using namespace std;

#define MIN(x,y) (x<y?x:y)

int n,k;

int arr[210];

int dp[210][210];

int solve(int l,int r){ //[l,r]
  if(l==r) return 0;  
  if(dp[l][r]!=1e9) return dp[l][r];
  
  for(int i=l;i<r;i++){
      int left=solve(l,i);
      int right=solve(i+1,r);
      dp[l][r]=MIN(dp[l][r],left+right+(arr[l]!=arr[i+1]));
  }
  //cout<<l<<' '<<r<<' '<<dp[l][r]<<'\n';
  return dp[l][r];
}


int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n+1;i++) fill(dp[i],dp[i]+n+1,1e9);
    cout<<solve(0,n-1);
}