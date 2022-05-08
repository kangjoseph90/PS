#include <iostream>
#include <vector>
#include <map>
using namespace std;

int mod=100000;

int n,m;

char board[25][25];

int dp[20005][25][25][2];

int key[20005],key_rev[1<<21];

int now_idx;

int cnt;

int pow(int a,int n){
    if(n==0) return 1;
    int ret=a;
    ret=(ret*pow(a,n-1))%mod;
    return ret;
}

struct pos{
    int r,c;
    pos next(){
        return {r+(c+1)/m,(c+1)%m};
    }
    bool out(){
        if(r>=n||c>=m) return true;
        return false;
    }
    char now_c(){
        return board[r][c];
    }
};

void print_bin(int n){
    for(int i=0;i<m;i++){
        cout<<(n&1);
        n>>=1;
    }
    cout<<endl;
}

void solve(pos now){ //400
    pos next=now.next();
    if(next.out()) return;
    for(int i=0;i<now_idx;i++){ //20000
        int idx=i,state=key[i];
        for(int ko_p=0;ko_p<2;ko_p++){ //2
            if(dp[idx][now.r][now.c][ko_p]==0) continue;
            dp[idx][now.r][now.c][ko_p]%=mod;
            if(now.now_c()=='?'||now.now_c()=='K'){
                dp[key_rev[state>>1]][next.r][next.c][1]+=dp[idx][now.r][now.c][ko_p];
                dp[key_rev[state>>1]][next.r][next.c][1]%=mod;
            }
            if(now.now_c()=='?'||now.now_c()=='O'){
                dp[key_rev[(state>>1)+(ko_p==1&&now.c>0?(1<<(m-2)):0)]][next.r][next.c][0]+=dp[idx][now.r][now.c][ko_p];
                dp[key_rev[(state>>1)+(ko_p==1&&now.c>0?(1<<(m-2)):0)]][next.r][next.c][0]%=mod;
            }
            if(now.now_c()=='?'||now.now_c()=='I'){
                if(state&1) continue;
                dp[key_rev[state>>1]][next.r][next.c][0]+=dp[idx][now.r][now.c][ko_p];
                dp[key_rev[state>>1]][next.r][next.c][0]%=mod;
            }
        }
    }
    solve(next);
}

void idx_fib(int now,int now_key){
    if(now==0){
        key[now_idx]=now_key;
        key_rev[now_key]=now_idx++;
        return;
    }
    idx_fib(now-1,now_key<<1);
    if(!(now_key&1)) idx_fib(now-1,(now_key<<1)+1);
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j]=='?') cnt++;
        }
    }
    idx_fib(m,0);
    dp[0][0][0][0]=1;
    solve({0,0});
    int ans=0;
    for(int i=0;i<20000;i++){
        ans+=dp[i][n-1][m-1][0];
        ans+=dp[i][n-1][m-1][1];
        ans%=mod;
    }
    if(board[n-1][m-1]=='?') ans*=3;
    cout<<((pow(3,cnt)-ans)%mod+mod)%mod<<endl;
    return 0;

}