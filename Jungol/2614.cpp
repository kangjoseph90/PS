#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9
#define MIN(x,y) (x<y?x:y)

struct edge{
    int s,e,cost;
};

int n,k;

vector<edge> edges;

int d[41];

int main(){
    cin>>n>>k;
    while(k--){
        int x,y,r;
        cin>>x>>y>>r;
        edges.push_back({x-1,y,r});
        edges.push_back({y,x-1,-r});
    }
    for(int i=0;i<n;i++){
        edges.push_back({i,i+1,1});
        edges.push_back({i+1,i,0});
    }
    for(int i=0;i<=n;i++) d[i]=INF;
    d[0]=0;   
    for(int i=1;i<n;i++){
        for(int j=0;j<edges.size();j++){
            int s=edges[j].s;
            int e=edges[j].e;
            int cost=edges[j].cost;
            if(d[s]==INF) continue;
            d[e]=MIN(d[e],d[s]+cost);
        }
    }
    bool cycle=false;
    for(int i=0;i<edges.size();i++){
        int s=edges[i].s;
        int e=edges[i].e;
        int cost=edges[i].cost;
        if(d[s]==INF) continue;
        if(d[e]>d[s]+cost) cycle=true;
    }
    if(cycle) cout<<"NONE";
    else
        for(int i=1;i<=n;i++){
            cout<<(d[i]>d[i-1]?'#':'-');
        }
}