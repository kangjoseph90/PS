#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int,char>> v;
        for(int i=0;i<n;i++){
            int a; cin>>a;
            v.push_back({a,'\0'});
        }
        for(int i=0;i<n;i++){
            char c; cin>>c;
            v[i].second=c;
        }
        vector<int> l,r;
        for(int i=0;i<n;i++){
            if(v[i].second=='R') r.push_back(-v[i].first);
            else l.push_back(v[i].first);
        }
        sort(l.begin(),l.end());
        sort(r.begin(),r.end());
        int lmr=n,lml=1;
        bool done=true;
        for(int i=0;i<r.size();i++){
            int now=-r[i];
            if(now>lmr) done=false;
            lmr--;
        }
        for(int i=0;i<l.size();i++){
            int now=l[i];
            if(now<lml) done=false;
            lml++;
        }
        cout<<(done?"YES":"NO")<<'\n';
    }


}