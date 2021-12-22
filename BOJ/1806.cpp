#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,s;
    cin>>n>>s;
    vector<int> v(n+1),psum(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        psum[i]=psum[i-1]+v[i];
    }
    if(psum[n]<s){
        cout<<0<<endl;
        return 0;
    }
    int l=0,r=0;
    int ans=INT_MAX;
    while(r<=n){
        if(psum[r]-psum[l]<s){
            r++;
        }
        else{
            ans=min(ans,r-l);
            l++;
        }
    }
    cout<<ans<<endl;

}