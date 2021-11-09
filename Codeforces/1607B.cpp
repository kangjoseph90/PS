#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--){
        ll x0,n0; cin>>x0>>n0;
        ll n=4*(n0/4)+1;
        for(;n<=n0;n++){
            if(x0%2) x0+=n;
            else x0-=n;
        }
        cout<<x0<<'\n';
    }
}