#include <iostream>
#include <climits>
using namespace std;

int n;


int a_temp[100001];
int arr[100001];

int ord[6][4]={
    {0,1,2,3},
    {0,1,3,2},
    {0,2,1,3},
    {0,2,3,1},
    {0,3,1,2},
    {0,3,2,1}
};

int solve(){

    int cnt[4],togo[4][4],idx[4];
    
    for(int i=0;i<4;i++){
        cnt[i]=idx[i]=0;
        for(int j=0;j<4;j++){
            togo[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++) cnt[arr[i]]++;

    for(int i=1;i<=3;i++){
        idx[i]=idx[i-1]+cnt[i];
        for(int j=idx[i-1]+1;j<=idx[i];j++){
            togo[i][arr[j]]++;
        }
    }    
    int ans=0;
    int t=0;
    for(int i=1;i<=3;i++){
        for(int j=i+1;j<=3;j++){
            ans+=min(togo[i][j],togo[j][i]);
            t=max(t,abs(togo[i][j]-togo[j][i]));
        }
    }
    return ans+2*t;

}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a_temp[i];
    }
    int ans=INT_MAX;
    for(int i=0;i<6;i++){
        for(int j=1;j<=n;j++){
            arr[j]=ord[i][a_temp[j]];
        }
        ans=min(ans,solve());
    }
    cout<<ans<<'\n';

}