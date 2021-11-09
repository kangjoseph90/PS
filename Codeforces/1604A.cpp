#include <bits/stdc++.h>

using namespace std;


int t,n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            int a; cin>>a;
            ans=max(ans,a-i);
        }
        cout<<ans<<'\n';
    }
    
}