#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll x,int n){
    ll ret=1;
    for(int i=0;i<n;i++) ret*=x;
    return ret;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll square=0,cube=0,both=0;
        while(power(square+1,2)<=n) square++;
        while(power(cube+1,3)<=n) cube++;
        while(power(both+1,6)<=n) both++;
        cout<<square+cube-both<<endl;
    }

}