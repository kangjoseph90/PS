#include <bits/stdc++.h>

using namespace std;

char board[100][100];

int n,m;

struct v2{
    int x,y;
    bool out(void){
        if(x<0||x>=n||y<0||y>=m) return true;
        return false;
    }
    char get(void){
        return board[x][y];
    }

    v2 operator+(v2 &op){
        return {x+op.x,y+op.y};
    }
};

v2 d[4]={
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};

bool visited[100][100];

int dfs(v2 now){
    int ret=0;
    if(visited[now.x][now.y]==false) ret++;
    visited[now.x][now.y]=true;
    for(int i=0;i<4;i++){
        v2 next=now+d[i];
        if(next.out()) continue;
        if(board[next.x][next.y]<=board[now.x][now.y]||board[next.x][next.y]=='9') continue;
        ret+=dfs(next);
    }
    return ret;
}

void vis_clear(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) visited[i][j]=false;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    
    vector<int> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v2 now={i,j};
            bool lower=true;
            for(int k=0;k<4;k++){
                v2 nearby=now+d[k];
                if(nearby.out()) continue;
                if(nearby.get()<=now.get()) lower=false;
            }
            if(lower) {
                vis_clear();
                int temp=dfs(now);
                v.push_back(temp);
            }
        }

    }
    sort(v.begin(),v.end(),greater<>());
    cout<<v[0]*v[1]*v[2]<<endl;


}