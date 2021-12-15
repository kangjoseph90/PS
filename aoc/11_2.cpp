#include <bits/stdc++.h>

using namespace std;

int board[10][10];

int n,m;

struct v2{
    int x,y;
    v2 operator+(v2 &op){
        return {x+op.x,y+op.y};
    }
    bool out(){
        if(x<0||x>=n||y<0||y>=m) return true;
        return false;
    }
};

v2 d[8]={
    {0,1},
    {0,-1},
    {1,0},
    {-1,0},
    {1,1},
    {1,-1},
    {-1,1},
    {-1,-1},
};


int flash(queue<v2> &q){
    int ret=0;
    while(q.size()){
        v2 now=q.front();
        q.pop();
        ret++;
        board[now.x][now.y]=0;
        for(auto dir:d){
            v2 next=now+dir;
            if(next.out()) continue;
            if(board[next.x][next.y]==0) continue;
            if(++board[next.x][next.y]==10) q.push(next);
        }
    }
    return ret;
}

int run(){
    for(int i=1;true;i++){
        queue<v2> q;
        for(int j=0;j<n;j++) 
            for(int k=0;k<m;k++)
                if(++board[j][k]==10) q.push({j,k});
        if(flash(q)==n*m) return i;
    }
    return -1;
}


int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            char c; cin>>c;
            board[i][j]=c-'0';
        }

    cout<<run();

}