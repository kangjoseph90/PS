#include <iostream>
#include <string>
using namespace std;

string color[4];

char side[4][4];

int ord[12][4]={
    {4,1,5,3},
    {1,5,3,4},
    {5,3,4,1},
    {3,4,1,5},
    {4,2,5,0},
    {2,5,0,4},
    {5,0,4,2},
    {0,4,2,5},
    {0,1,2,3},
    {1,2,3,0},
    {2,3,0,1},
    {3,0,1,2}
};

int ans=0;

int visited[200000];

int solve(int idx){
    int ret=0;
    if(idx==4){
        int hash=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                hash+=side[i][j]*(i*4+j+1)*(i*4+j+1);
                
            }
        }
        if(visited[hash]) return 0;
        visited[hash]=1;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                for(int k=j+1;k<4;k++){
                    if(side[j][i]==side[k][i]) return 0;
                }
            }
        }
        return 1;
    }
    for(int i=0;i<12;i++){
        for(int j=0;j<4;j++){
            side[idx][j]=color[idx][ord[i][j]];
            ret+=solve(idx+1);
        }
        for(int j=3;j>=0;j--){
            side[idx][-j+3]=color[idx][ord[i][j]];
            ret+=solve(idx+1);
        }
    }
    return ret;
}

int main(){
    for(int i=0;i<4;i++){
        cin>>color[i];
    }
    cout<<solve(0);
}