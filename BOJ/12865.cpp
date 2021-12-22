#include <bits/stdc++.h>

using namespace std;

int dp[101][100001];

int n,k;

pair<int,int> item[101];
bool visited[101][100001];
int ans=0;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>item[i].first>>item[i].second;
    }
    queue<pair<int,int>> q;    
    q.push({0,0});
    while(q.size()){
        pair<int,int> now=q.front();
        //cout<<now.first<<' '<<now.second<<endl;
        q.pop();
        if(now.first>=n){
            ans=max(ans,dp[now.first][now.second]);        
            continue;    
        }
        if(visited[now.first][now.second]) continue;
        visited[now.first][now.second]=true;
        if(now.second+item[now.first+1].first<=k){
            dp[now.first+1][now.second+item[now.first+1].first]=max(dp[now.first+1][now.second+item[now.first+1].first],dp[now.first][now.second]+item[now.first+1].second);
            q.push({now.first+1,now.second+item[now.first+1].first});
        }
        dp[now.first+1][now.second]=max(dp[now.first+1][now.second],dp[now.first][now.second]);
        q.push({now.first+1,now.second});
    }
    cout<<ans<<endl;
}