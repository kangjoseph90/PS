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



int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    
    int ans=0;
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
                ans+=now.get()-'0'+1;
            }
        }
    }
    cout<<ans;


}