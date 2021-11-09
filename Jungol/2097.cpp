#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
#define all(x) x.begin(),x.end()
using namespace std;

void setup(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}


typedef struct aa{
    int len,node,from;
}aa;

struct compare{
    bool operator()(aa a, aa b){
        return a.len<b.len;
    }
};

priority_queue<aa,vector<aa>,compare> pq;

int n,m;

int board[101][101];

int dp[101];

int from[101];

void solve(){
    pq.push({0,1,-1});
    while(pq.size()){
        aa now=pq.top();
        pq.pop();
        
        if(dp[now.node]!=-1) continue;
        from[now.node]=now.from;
        dp[now.node]=-now.len;
        if(now.node==m) {
            cout<<-now.len<<'\n';
            return;
        }
        for(int i=1;i<=n;i++){
            if(i==now.node) continue;
            int next=i;
            int len=board[now.node][i];
            pq.push({now.len-len,next,now.node}); 
        }
    }
}

int main(){
    setup;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        dp[i]=-1;
        for(int j=1;j<=n;j++) cin>>board[i][j];
    }
    solve();
    stack<int> s;
    while(m!=-1){
        s.push(m);
        m=from[m];
    }
    while(s.size()){
        cout<<s.top()<<' ';
        s.pop();
    }

}