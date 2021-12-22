#include <bits/stdc++.h>
using namespace std;

int n,m;

int board[15][15],ans[15][15];

struct v2{
    int x,y;
    v2 operator+(v2 &op){
        return {x+op.x,y+op.y};
    }
    bool out(){
        return x<0||x>=n||y<0||y>=m;
    }
    v2 next(){
        if(x+1>=n) return {0,y+1};
        return {x+1,y};
    }
    int get(){
        return board[y][x];
    }
    void update(){
        board[y][x]=(board[y][x]+1)%2;
    }
};

v2 d[4]={ //U D R L
    {0,-1},
    {0,1},
    {1,0},
    {-1,0}
};


bool done=false;



void solve(v2 now){
    if(done) return;
    if(now.out()){
        done=true;
        return;
    }
    v2 up=now+d[0],left=now+d[3];
    v2 down=now+d[1],right=now+d[2];
    if(down.out()&&!left.out()){
        if(right.out()){
            if(up.get()!=left.get()||left.get()!=now.get()){
                return;
            }
        }
        else{
            if(up.get()!=left.get()) return;
        }
    }
    if(up.out()){
        ans[now.y][now.x]=0;
        solve(now.next());
        if(done) return;
        ans[now.y][now.x]=1;
        now.update();
        for(auto dir:d){
            v2 next=now+dir;
            if(next.out()) continue;
            next.update();
        }
        solve(now.next());
        if(done) return;
        now.update();
        for(auto dir:d){
            v2 next=now+dir;
            if(next.out()) continue;
            next.update();
        }
    }
    else{
        ans[now.y][now.x]=up.get();
        if(ans[now.y][now.x]){
            now.update();
            for(auto dir:d){
                v2 next=now+dir;
                if(next.out()) continue;
                next.update();
            }
        }
        solve(now.next());
        if(done) return;
        if(ans[now.y][now.x]){
            now.update();
            for(auto dir:d){
                v2 next=now+dir;
                if(next.out()) continue;
                next.update();
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    solve({0,0});
    if(!done) cout<<"IMPOSSIBLE"<<endl;
    else
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<ans[i][j]<<' ';
            }
            cout<<endl;
        }
}