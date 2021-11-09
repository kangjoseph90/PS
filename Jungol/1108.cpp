#include <iostream>
#include <vector>

using namespace std;

#define MIN(x,y) (x<y?x:y)
#define INF 1e9

int n;

vector<int> edge[501];

int len[501][501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed;
    cout.precision(3);
    cin>>n;
    for(int i=0;i<501;i++) fill(len[i],len[i]+501,INF);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        len[a][b]=1;
    }
    
    for(int i=1;i<501;i++){
        for(int j=1;j<501;j++){
            for(int k=1;k<501;k++){
                if(j==k){
                    continue;
                }
                len[j][k]=MIN(len[j][k],len[j][i]+len[i][k]);
            }
        }
    }
    int sum=0;
    int cnt=0;
    for(int i=1;i<501;i++){
        for(int j=1;j<501;j++){
            if(len[i][j]!=INF) {
                sum+=len[i][j];
                cnt++;
            }
        }
    }
    cout<<(double)sum/cnt;

}