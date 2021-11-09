#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,l;


vector<int> v;

vector<pair<int,int>> a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>l;
    for(int i=0;i<n;i++){
        int t; cin>>t;
        v.push_back(t);
    }

    sort(v.begin(),v.end());

    int ans=0;

    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        auto iter=lower_bound(v.begin(),v.end(),x+y-l);
        if(iter==v.end()) continue;
        if(*iter<=x-y+l) ans++;
    }
    cout<<ans<<'\n';
}