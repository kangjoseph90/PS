#include <iostream>
#include <queue>
#include <cmath>
using namespace std;


int n;

int board[26][26];

bool visited[500000];


struct v2{
    int y,x;

    v2 operator+(v2 op){
        return {y+op.y,x+op.x};
    }

    int h(){
        return y*(n+1)+x;
    }

    bool operator==(v2 op){
        return (y==op.y&&x==op.x);
    }

    bool in(){
        return {y>0&&y<=n&&x>0&&x<=n};
    }

    bool blocked(){
        return board[y][x];
    }

};

v2 d[9]={
    {0,0},
    {0,1},
    {0,-1},
    {1,0},
    {-1,0},
    {-1,-1},
    {-1,1},
    {1,-1},
    {1,1},
};

struct aa{
    v2 gd,gs;
    int cnt;

    int h(){
        return gd.h()*(n+1)*(n+1)+gs.h();
    }

    bool coll(){
        return (abs(gd.y-gs.y)<=1&&abs(gd.x-gs.x)<=1);
    }

    bool in(){
        return gd.in()&&gs.in();
    }

    bool blocked(){
        return gd.blocked()||gs.blocked();
    }

};


v2 h_gd,h_gs;



int solve(v2 s_gd,v2 s_gs){
    queue<aa> q;
    q.push({s_gd,s_gs,0});
    visited[q.front().h()]=true;

    while(q.size()){
        aa now=q.front();
        q.pop();
        if(now.gd==h_gd&&now.gs==h_gs) return now.cnt;
        for(auto& nd1:d){
            for(auto& nd2:d){
                aa next=now;
                next.cnt++;
                next.gd=next.gd+nd1;
                next.gs=next.gs+nd2;
                if(!next.in()) continue;
                if(next.coll()) continue;
                if(next.blocked()) continue;
                if(visited[next.h()]) continue;
                visited[next.h()]=true;
                q.push(next);
            }
        }
    }

    return 0;
}


int main(){
    cin>>n;
    v2 s_gd,s_gs;

    int a,b,c,d;

    cin>>a>>b>>c>>d;
    s_gd={a,b};
    h_gd={c,d};

    cin>>a>>b>>c>>d;
    s_gs={a,b};
    h_gs={c,d};

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>board[i][j];

    cout<<solve(s_gd,s_gs);


}