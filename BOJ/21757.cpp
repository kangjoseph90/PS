#include <iostream>
#include <vector>

using namespace std;

#define int long long

int a[100001],s[100001];

int n;

vector<int> v;
int dp[4]={1,};

int32_t main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    if(s[n]%4){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(s[n]==0){
            if(s[i]==0) v.push_back(s[n]);
            continue;
        }
        if(s[i]%(s[n]/4)==0){
            v.push_back(s[i]);
        }
    }
    for(int k=0;k<v.size()-1;k++){
        for(int i=4;i>0;i--){
            if(s[n]==0){
                dp[i]+=dp[i-1];
                continue;
            }
            if(v[k]/(s[n]/4)==i){
                dp[i]+=dp[i-1]; 
            }
        }
    }
    cout<<dp[3];

}