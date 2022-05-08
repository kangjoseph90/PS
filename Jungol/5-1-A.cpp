#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
#define min(x,y) ((x)>(y)?(y):(x))
int arr[100000];

vector<int> idx[100001];

int dp[100000];

int n;

int ans=1;

int32_t main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        idx[arr[i]].push_back(i);
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            dp[i]=1;
            continue;
        }
        auto iter=lower_bound(idx[arr[i]].begin(),idx[arr[i]].end(),i+1);
        if(iter==idx[arr[i]].end()) dp[i]=n-i;
        else dp[i]=*iter-i;
        dp[i]=min(dp[i],dp[i+1]+1);
        ans+=dp[i];
    }
    cout<<ans;
}