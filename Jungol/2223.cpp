#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9
#define MIN(x,y) (x<y?x:y)


struct edge{
    int s,e,cost;
};

vector<edge> edges;

int d[501];

int t,n,m,b;

void input(){
    edges.clear();
    cin>>n>>m>>b;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
        edges.push_back({b,a,c});
    }
    while(b--){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,-c});
    }
}

void solve(){
    input();
    for(int i=1;i<=n;i++) d[i]=INF;
    d[1]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<edges.size();j++){
            int s=edges[j].s;
            int e=edges[j].e;
            int cost=edges[j].cost;
            if(d[s]==INF) continue;
            d[e]=MIN(d[e],d[s]+cost);
        }
    }
    for(int j=0;j<edges.size();j++){
        int s=edges[j].s;
        int e=edges[j].e;
        int cost=edges[j].cost;
        if(d[s]==INF) continue;
        if(d[e]>d[s]+cost) {
			cout<<"YES"<<'\n';
			return;
        }
    }
    
    cout<<"NO"<<'\n';
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        solve();
    }
}
