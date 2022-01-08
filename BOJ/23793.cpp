#include <bits/stdc++.h>

using namespace std;


int n,m;
vector<pair<int,int>> edge[100001];

priority_queue<pair<int,int>> pq[3]; //cost,node

bool visited[3][100001];

int solve(int s,int e,int avoid,int i){
    pq[i].push({0,s});
    int ans1=0;
    while(!pq[i].empty()){
        int cost=-pq[i].top().first;
        int node=pq[i].top().second;
        pq[i].pop();
        if(node==e){
            return cost;
        }
        if(visited[i][node]) continue;
        //cout<<node<<endl
        visited[i][node]=true;
        for(auto next:edge[node]){
            int n_cost=cost+next.second;
            int n_node=next.first;
            if(visited[i][n_node]||n_node==avoid){
                continue;
            }
            pq[i].push({-n_cost,n_node});
        }
    }
    return -1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        edge[u].push_back({v,w});
    }
    int x,y,z; cin>>x>>y>>z;
    int xy=solve(x,y,-1,0);
    int yz=solve(y,z,-1,1);
    int xz=solve(x,z,y,2);
    if(xy==-1||yz==-1) cout<<-1<<' ';
    else cout<<xy+yz<<' ';
    if(xz==-1) cout<<-1<<endl;
    else cout<<xz<<endl;
}