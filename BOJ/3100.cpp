#include <bits/stdc++.h>

using namespace std;
char board1[6][9],board2[9][6];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<6;i++){
        for(int j=0;j<9;j++) {
            cin>>board1[i][j];
            board2[j][i]=board1[i][j];
        }
    }
    int ans=INT_MAX;
    for(char a='A';a<='Z';a++){
        for(char b='A';b<='Z';b++){
            for(char c='A';c<='Z';c++){
                if(a==b||b==c) continue;
                int now=0;
                for(int j=0;j<2;j++){
                    for(int k=0;k<9;k++){
                        if(board1[j][k]!=a) now++;
                        if(board1[j+2][k]!=b) now++;
                        if(board1[j+4][k]!=c) now++;
                    }  
                }
                ans=min(ans,now);
                now=0;
                for(int j=0;j<3;j++){
                    for(int k=0;k<6;k++){
                        if(board2[j][k]!=a) now++;
                        if(board2[j+3][k]!=b) now++;
                        if(board2[j+6][k]!=c) now++; 
                    }
                }
                ans=min(ans,now);
            }
        }
    }
    cout<<ans<<endl;
    
    
}