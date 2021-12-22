#include <bits/stdc++.h>
using namespace std;
#define int long long 


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int p,q,r;
    cin>>p>>q>>r;
    for(int i=0;i<15*28*19;i++){
        if(i%15==p-1&&i%28==q-1&&i%19==r-1){
            cout<<i+1<<endl;
            break;
        }
    }
}