#include <bits/stdc++.h>

using namespace std;

#define int long long 

set<int> s;

int ans;

int bnd=((int)1<<31);

int32_t main(){
    int m,n;
    cin>>m>>n;
    vector<int> v;
    for(int i=0;i<m;i++){
        int a; cin>>a;
        v.push_back(a);
        s.insert(a);
    }
    while(n--){
        ans=*s.begin();
        s.erase(s.begin());
        //cout<<ans<<endl;
        for(auto p:v){
            if(ans*p<bnd)
                s.insert(ans*p);
            if(s.size()>n)
                bnd=*s.rbegin();
            //cout<<"insert "<<ans*p<<endl;
        }
    }
    cout<<ans<<endl;
}