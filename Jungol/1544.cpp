#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
int n;

int ans=INT_MAX;

vector<int> edge[51];

int point[51];

int visited[51];

int solve(int idx){
    int ret=0;
    queue<pair<int,int>> q;
    q.push({idx,0});
    visited[idx]=idx;
    while(q.size()){
        int now=q.front().first;
        int len=q.front().second;
        ret=MAX(ret,len);
        q.pop();
        for(int i=0;i<edge[now].size();i++){
            int next=edge[now][i];
            if(visited[next]==idx) continue;
            q.push({next,len+1});
            visited[next]=idx;
        }
    }
    return ret;
}

int main(){
    cin>>n;
    while(true){
        int a,b;
        cin>>a>>b;
        if(a==-1&&b==-1) break;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int ans=INT_MAX;
    for(int i=1;i<=n;i++){
        point[i]=solve(i);
        ans=MIN(ans,point[i]);
    }
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(point[i]==ans) v.push_back(i);
    }
    cout<<ans<<' '<<v.size()<<'\n';
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }



}