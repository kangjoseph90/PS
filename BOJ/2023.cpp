#include <bits/stdc++.h>
using namespace std;
#define int long long 


int n;

bool is_prime(int x){
    if(x==0||x==1) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

void solve(int value,int cnt){
    if(cnt==n){
        cout<<value<<endl;
        return;
    }
    for(int i=0;i<10;i++){
        int n_value=value*10+i;
        if(is_prime(n_value)) solve(n_value,cnt+1);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    solve(0,0);
}