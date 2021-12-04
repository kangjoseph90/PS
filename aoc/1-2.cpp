#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long l,m,r,t,cnt=0;
    l=m=r=1e9;
    while(!cin.eof()){
        cin>>t;
        if(l+m+r<m+r+t) cnt++;
        l=m; m=r; r=t;
    }
    cout<<cnt;

}