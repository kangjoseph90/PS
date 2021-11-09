#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int mount[100][100];

int n;
int y,x;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};


bool visited[100][100];

struct aa{
    int cost;
    int y,x;
};

struct compare{
    bool operator()(aa a,aa b){
        return a.cost>b.cost;
    }

};

priority_queue<aa,vector<aa>,compare> pq;

int d(int y1,int x1,int y2,int x2){
    if(mount[y1][x1]==mount[y2][x2]) return 0;
    if(mount[y1][x1]>mount[y2][x2]) return mount[y1][x1]-mount[y2][x2];
    else return (mount[y2][x2]-mount[y1][x1])*(mount[y2][x2]-mount[y1][x1]);

}

int solve(){
    for(int i=0;i<n;i++) {
        pq.push({mount[0][i]*mount[0][i],0,i});
        pq.push({mount[n-1][i]*mount[n-1][i],n-1,i});
    }
    for(int i=1;i<n-1;i++){
        pq.push({mount[i][0]*mount[i][0],i,0});
        pq.push({mount[i][n-1]*mount[i][n-1],i,n-1});
    }
    while(pq.size()){
        aa now=pq.top();
        pq.pop();
        if(visited[now.y][now.x]) continue;
        visited[now.y][now.x]=true;
        if(now.y==y&&now.x==x) return now.cost;
        for(int i=0;i<4;i++){
            int ny=now.y+dy[i];
            int nx=now.x+dx[i];
            if(ny<0||ny==n||nx<0||nx==n) continue;
            int len=d(now.y,now.x,ny,nx);
            if(!visited[ny][nx]) pq.push({now.cost+len,ny,nx});
        }
    }
    return -1;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>y>>x;
    y--;
    x--;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>mount[i][j];
    }
    cout<<solve();

}