#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef struct pos{
    int x,y;
}pos;

vector<pos> v;

int n,k;

int vis[1002];

vector<pair<int,int>> edge[1002];

int d(int a,int b){
    int dx=abs(v[a].x-v[b].x);
    int dy=abs(v[a].y-v[b].y);
    int temp=sqrt(dx*dx+dy*dy)/10;
    if(temp*temp*100==dx*dx+dy*dy) return temp;
    return temp+1;
}


bool check(int x){
    queue<pair<int,int>> q; //node, cnt;
    q.push({0,0});
    vis[0]=x;
    //cout<<'\n';
    while(q.size()){
        int now=q.front().first;
        //cout<<now<<' ';
        int cnt=q.front().second;
        q.pop();
        if(now==n-1) return true;
        if(cnt>k) continue;
        for(int i=0;i<edge[now].size();i++){
            int next=edge[now][i].first;
            int cost=edge[now][i].second;
            if(cost>x||vis[next]==x) continue;
            q.push({next,cnt+1});
            vis[next]=x;
        }
    }
    return false;
}

int solve(){
    int s=0,e=1500;
    while(s<=e){
        int m=(s+e)/2;
        //cout<<m<<'\n';
        if(check(m)) e=m-1;
        else s=m+1;
    }
    return e+1;
}

int main(){
    cin>>n>>k;
    v.push_back({0,0});
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    v.push_back({10000,10000});
    n+=2;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int temp=d(i,j);
            edge[i].push_back({j,temp});
            edge[j].push_back({i,temp});
        }
    }
    cout<<solve();
}