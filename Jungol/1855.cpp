#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


int dp[501][801];

int start[501];

vector<pair<int,int>> edge[801]; //node, cost

int n,p,c;

struct compare{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
};

void solve(int idx){
    fill(dp[idx],dp[idx]+p+1,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    pq.push({start[idx],0});
    while(pq.size()){
        int node=pq.top().first;
        int cost=pq.top().second;
        pq.pop();
        if(dp[idx][node]!=-1) continue;
        dp[idx][node]=cost;
        for(int i=0;i<edge[node].size();i++){
            int next=edge[node][i].first;
            if(dp[idx][next]!=-1) continue;
            pq.push({next,cost+edge[node][i].second});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>p>>c;
    while(c--){
        int i,j,cost;
        cin>>i>>j>>cost;
        edge[i].push_back({j,cost});
        edge[j].push_back({i,cost});
    }
    for(int i=1;i<=n;i++) {
        cin>>start[i];
        solve(i);
    }
    int ans=INT_MAX;
    for(int i=1;i<=p;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            if(dp[j][i]==-1) {
                sum=INT_MAX;
                break;
            }
            sum+=dp[j][i];
        }
        if(ans>sum) ans=sum;
    }
    cout<<ans;
}
