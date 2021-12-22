#include <bits/stdc++.h>
using namespace std;
#define int long long 


int n;

bool not_prime[4000001];

vector<int> p;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    p.push_back(0);
    for(int i=2;i<=n;i++){
        if(not_prime[i]) continue;
        p.push_back(p.back()+i);
        for(int j=2;j*i<=n;j++){
            not_prime[j*i]=true;
        }
    }
    int ans=0;
    int l=0,r=0;
    while(r<p.size()){
        if(p[r]-p[l]>n) l++;
        else if(p[r]-p[l]<n) r++;
        else{
            ans++;
            r++;
        }
    }
    cout<<ans<<endl;
}