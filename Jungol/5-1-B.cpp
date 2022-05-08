#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define int long long
#define min(x,y) ((x)>(y)?(y):(x))
using namespace std;

const int INF=LLONG_MAX;

vector<int> pt[500000];
vector<int> p;

int n,m,r;

int ans=INF;


int32_t main(){
    cin.sync_with_stdio(false);
    cin>>n>>m>>r;

    if(m>5000) {
        cout<<INF<<endl;
        return 0;
    }

    while(n--){
        int y,x;
        cin>>y>>x;
        pt[y].push_back(x);
        p.push_back(x);
    }

    for(int i=0;i<m;i++) {
        sort(pt[i].begin(),pt[i].end());
        pt[i].insert(pt[i].begin(),pt[i].back()-r);
        pt[i].push_back(pt[i][1]+r);
    }
    
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    
    for(int i=0;i<p.size();i++){
        int now=p[i];
    }
} 