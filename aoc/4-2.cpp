#include <iostream>
#include <map>
#include <queue>
using namespace std;

#define int long long

int board[5][5];

priority_queue<pair<int,pair<int,int>>> ord;

int sum;

map<int,int> idx;

pair<int,int> ans={0,1e9};

int n;

bool check(){
    for(int i=0;i<5;i++){
        bool done1,done2;
        done1=done2=true;
        for(int j=0;j<5;j++){
            if(board[i][j]!=-1) done1=false;
            if(board[j][i]!=-1) done2=false;
        }
        if(done1||done2) return true;
    }
    return false;
}

pair<int,int> run(){
    while(ord.size()){
        int x=ord.top().second.first;
        int y=ord.top().second.second;
        int cnt=ord.top().first;
        ord.pop();
        int now=board[x][y];
        sum-=board[x][y];
        board[x][y]=-1;
        if(check()){
            return {-cnt,now*sum};
        }
    }   
    return {30,0};
}

int32_t main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int t; cin>>t;
        idx[t]=i;
    }
    cin>>n;
    while(n--){
        while(ord.size()) ord.pop();
        sum=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                board[i][j]=0;
                cin>>board[i][j];
                sum+=board[i][j];
                ord.push({-idx[board[i][j]],{i,j}});
            }
        }
        pair<int,int> now=run();
        if(ans.first<now.first) ans=now;
    }
    cout<<ans.second<<endl;
}