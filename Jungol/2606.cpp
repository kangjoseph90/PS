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

typedef struct pos{
    int z,y,x;
}pos;


int dy[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

int board[100][100][100];

int m,n,h;

int cnt;

queue<pos> q;

queue<pos> temp;

bool check(pos t){
    if(t.z<0||t.z==h||t.y<0||t.y==n||t.x<0||t.x==m) return true;
    return false;

}

void run(int t){
    if(cnt==0) {
        cout<<t;
        return;
    }
    while(q.size()){
        pos now=q.front();
        q.pop();
        for(int i=0;i<6;i++){
            pos next={now.z+dz[i],now.y+dy[i],now.x+dx[i]};
            if(check(next)) continue;
            if(board[next.z][next.y][next.x]==0){
                board[next.z][next.y][next.x]=1;
                cnt--;
                temp.push(next);
            }
        }
    }
    if(temp.empty()&&cnt) {
        cout<<-1;
        return;
    }
    while(temp.size()){
        q.push(temp.front());
        temp.pop();
    }
    run(t+1);
}

int main(){
    setup();
    cin>>m>>n>>h;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                int a; cin>>a;
                board[i][j][k]=a;
                if(a==1) q.push({i,j,k});
                if(a==0) cnt++;
            }
        }
    }
    run(0);
}