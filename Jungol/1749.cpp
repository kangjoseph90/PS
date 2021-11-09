#include <iostream> 
#include <vector>
using namespace std;

vector<int> choice;

#define MAX(x,y) (x>y?x:y)

int dp[2][501][501];

int solve(int player,int l,int r){
    if(r<0||l<0) return 1;
    if(dp[player][l][r]!=-1) return dp[player][l][r];
    int ret=0,t;
    for(int i=0;i<3;i++){
        t=1-solve(1-player,l-choice[i],r);
        ret=MAX(ret,t);
        t=1-solve(1-player,l,r-choice[i]);
        ret=MAX(ret,t);
    }
    return dp[player][l][r]=ret;
}

int main(){
    for(int i=0;i<501;i++){
        for(int j=0;j<501;j++){
            dp[0][i][j]=-1;
            dp[1][i][j]=-1;
        }
    }
    for(int i=0;i<3;i++){
        int t;
        cin>>t;
        choice.push_back(t);
    }
    for(int i=0;i<5;i++){
        int a,b;
        cin>>a>>b;
        cout<<(solve(0,a,b)?'A':'B')<<'\n';
    }
}