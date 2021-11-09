#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define MIN(x,y) (x<y?x:y)

int n,k;

int board[51][51];

bool visited[51][51];


struct v2{
    int y,x;

    v2 operator+(v2 op){
        return {y+op.y,x+op.x};
    }
    v2 operator-(v2 op){
        return {y-op.y,x-op.x};
    }
    v2 operator/(int op){
        return {y/op,x/op};
    }
    void operator+=(v2 op){
        y=y+op.y;
        x=x+op.x;
    }
    bool operator==(v2 op){
        return (y==op.y&&x==op.x);
    }
    bool operator!=(v2 op){
        return !(*this==op);
    }
    bool in(){
        return {y>0&&y<=n&&x>0&&x<=n};
    }
    void input(){
        cin>>y>>x;
    }
    void output(){
        cout<<y<<' '<<x<<' ';
    }
    int norm(){
        return abs(y)+abs(x);
    }
    v2 resize(){
        return (*this)/(*this).norm();
    }
    int get_cost(){
        return board[y][x]*k+1;
    }
};

v2 from[51][51];

v2 s,e;

v2 d[4]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};


void input(){
    cin>>n;
    s.input(); e.input();
    cin>>k; k--;
    int t; cin>>t;
    while(t--){
        int p;
        cin>>p;
        v2 last,now;
        last.input();
        while(--p){
            now.input();
            v2 d=(now-last).resize();
            for(;last!=now;last+=d){
                board[last.y][last.x]=1;
            }
        }
        board[now.y][now.x]=1;
    }
}

struct aa{
    int cost;
    v2 now,last;
};

class compare{
public:
    bool operator()(aa &a,aa &b){
        return a.cost>b.cost;
    }
};



int solve(){ 
    priority_queue<aa,vector<aa>,compare> q;
    q.push({s.get_cost(),s,s});

    while(q.size()){
        int cost=q.top().cost;
        v2 now=q.top().now, last=q.top().last;
        q.pop();
        if(visited[now.y][now.x]) continue;
        visited[now.y][now.x]=true; 
        from[now.y][now.x]=last;
        if(now==e) return cost;
        for(auto& nd:d){
            v2 next=now+nd;
            if(!next.in()) continue;
            if(visited[next.y][next.x]) continue;
            q.push({cost+next.get_cost(),next,now});
        }
    }
    return 0;
}

int main(){
    input();
    cout<<solve()<<'\n';
    vector<v2> v;
    v2 now=e;
    while(true){
        v.push_back(now);
        if(now==from[now.y][now.x]) break;
        now=from[now.y][now.x];
    }
    vector<v2> ans;
    ans.push_back(s);
    for(int i=v.size()-2;i>0;i--){
        if((v[i]-v[i+1])!=(v[i-1]-v[i])) ans.push_back(v[i]);
    }
    ans.push_back(e);
    cout<<ans.size()<<' ';
    for(auto& item:ans){
        item.output();
    }
}