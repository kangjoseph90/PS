#include <iostream>

using namespace std;

int n;

int arr[1000];
int cnt[4];

int togo[4][4]; 

int idx[4];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        cnt[arr[i]]++;
    }
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
    cout<<ans+2*t<<'\n';

}