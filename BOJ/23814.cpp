#include <bits/stdc++.h>

using namespace std;

long long d,n,m,k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>d>>n>>m>>k;
    long long n_d=d-n%d,m_d=d-m%d;
    if(min(n_d,m_d)<=k%d){
        if(n_d+m_d<=k%d) cout<<k-n_d-m_d;
        else cout<<k-min(n_d,m_d);
    }
    else if(n_d+m_d<=k%d+d){
        cout<<k-n_d-m_d;
    }
    else{
        cout<<k;
    }
}