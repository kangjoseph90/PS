#include <iostream>
using namespace std;

int board[1000][1000];

int t;


void line(int x1,int y1,int x2,int y2){
    if(x1==x2){
        if(y1>y2) swap(y1,y2);
        for(;y1<=y2;y1++){
            board[x1][y1]++;
        }
    }
    else if(y1==y2){
        if(x1>x2) swap(x1,x2);
        for(;x1<=x2;x1++){
            board[x1][y1]++;
        }
    }   
    else if(abs(x1-x2)==abs(y1-y2)){
        for(;x1!=x2;x1+=(x2-x1)/abs(x2-x1),y1+=(y2-y1)/abs(y2-y1)){
            board[x1][y1]++;
        }
        board[x1][y1]++;
    }
}


int main(){
    cin>>t;
    while(t--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        line(x1,y1,x2,y2);
    }
    int cnt=0;
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            if(board[i][j]>1) cnt++;
        }
    }
    cout<<cnt;
}