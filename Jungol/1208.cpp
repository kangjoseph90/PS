#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n;

char ans;
int ans_len=INT_MAX;

struct compare{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
};

int check[26];

bool visited[130];


vector<pair<int,int>> edge[130]; //node, len;

void solve(){
    for(int i='A';i<'Z';i++){
        int start=i;
        fill(visited,visited+130,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        pq.push({start,0});
        while(pq.size()){
            pair<int,int> now=pq.top();
            pq.pop();
            if(visited[now.first]) continue;
            visited[now.first]=true;
            if(now.first=='Z'){
                if(ans_len>now.second){
                    ans=start;
                    ans_len=now.second;
                    break;
                }
            }
            for(int i=0;i<edge[now.first].size();i++){
                int next=edge[now.first][i].first;
                int len=edge[now.first][i].second;
                if(!visited[next]) pq.push({next,now.second+len});
            }
        }
    }
    cout<<ans<<' '<<ans_len<<'\n';
}

int main(){
    cin>>n;
    while(n--){
        char a,b;
        int c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    solve();
}