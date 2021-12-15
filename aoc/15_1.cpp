#include <bits/stdc++.h>

using namespace std;

int n,m;

int board[100][100];

struct v2{
    int x,y;
    v2 operator+(const v2 &op){
        return {x+op.x,y+op.y};
    }
    bool operator==(const v2 &op){
        return x==op.x&&y==op.y;
    }
    bool out(){
        if(x<0||x>=n||y<0||y>=m) return true;
        return false;
    }
};

class cmp{

public:
    bool operator()(pair<int,v2> n1,pair<int,v2> n2){
        return n1.first>n2.first;
    }
};

v2 d[4]={
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};

bool visited[100][100];

v2 goal;

int solve(){
    priority_queue<pair<int,v2>,vector<pair<int,v2>>,cmp> pq;
    pq.push({0,{0,0}});
    visited[0][0]=true;
    while(pq.size()){
        v2 now=pq.top().second;
        //cout<<now.x<<' '<<now.y<<endl;
        int cost=pq.top().first;
        pq.pop();
        if(now==goal) return cost;
        for(auto dir:d){
            v2 next=now+dir;
            if(next.out()) continue;
            if(visited[next.x][next.y]) continue;
            visited[next.x][next.y]=true;
            pq.push({cost+board[next.x][next.y],next});
        }
    }
    return -1;
}



int main(){
    cin>>n>>m;
    goal={n-1,m-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char t; cin>>t;
            board[i][j]=t-'0';
        }
    }
    cout<<solve()<<endl;

}