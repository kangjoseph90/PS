#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;

vector<pair<int,int>> edge[100001];

bool visited[100001];

struct compare{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
};

void solve(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    pq.push({1,0});
    while(pq.size()){
        int node=pq.top().first;
        int cost=pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node]=true;
        if(node==n){
            cout<<cost;
            return;
        }
        for(int i=0;i<edge[node].size();i++){
            int next=edge[node][i].first;
            if(!visited[next]) pq.push({next,cost+edge[node][i].second});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
    }
    solve();
}