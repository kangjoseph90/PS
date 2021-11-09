#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX(x,y) (x>y?x:y)

int n,m,x;

bool visited[10001];

vector<pair<int,int>> edge[1001];

int from[10001];

struct compare{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
};



void from_x(){
    fill(from,from+n+1,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    pq.push({x,0});
    while(pq.size()){
        int now=pq.top().first;
        int cost=pq.top().second;
        pq.pop();
        if(from[now]!=-1) continue;
        from[now]=cost;
        for(int i=0;i<edge[now].size();i++){
            int next=edge[now][i].first;
            int len=edge[now][i].second;
            if(from[next]==-1) pq.push({next,cost+len});
        }
    }
}

int solve(){
    from_x();
    int ret=0;
    for(int i=1;i<=n;i++){
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        pq.push({i,0});
        fill(visited,visited+n+1,false);
        while(pq.size()){
            int now=pq.top().first;
            int cost=pq.top().second;
            pq.pop();
            if(visited[now]) continue;
            visited[now]=true;
            if(now==x){
                ret=MAX(ret,cost+from[i]);
                break;
            }
            for(int i=0;i<edge[now].size();i++){
                int next=edge[now][i].first;
                int len=edge[now][i].second;
                if(!visited[next]) pq.push({next,cost+len});
            }
        }
    }
    return ret;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>x;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
    }
    cout<<solve();

}