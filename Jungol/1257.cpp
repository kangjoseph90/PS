#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
#define all(x) x.begin(),x.end()
using namespace std;

void setup(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n;

int ans;

int tree[2000001];

vector<pair<int,int>> arr;

int dp[500001];

int find(int s,int e,int node,int l,int r){
    if(s>r||e<l) return 0;
    if(s>=l&&e<=r) return tree[node];
    int m=(s+e)/2;
    int l_=find(s,m,node*2,l,r);
    int r_=find(m+1,e,node*2+1,l,r);
    return MAX(l_,r_);
}

int update(int s,int e,int node,int idx){
    if(s>idx||e<idx) return tree[node];
    if(s==e) return tree[node]=dp[idx];
    int m=(s+e)/2;
    int l=update(s,m,node*2,idx);
    int r=update(m+1,e,node*2+1,idx);
    return tree[node]=MAX(l,r);
}

void solve(){
    for(int i=0;i<arr.size();i++){
        int key=arr[i].first;
        int val=arr[i].second;
        int mx=find(1,500000,1,1,val-1);
        dp[val]=mx+1;
        update(1,500000,1,val);
    }
    ans=tree[1];
    cout<<n-ans<<'\n';
    stack<int> lis_idx;
    for(int i=n-1;i>=0;i--){
        int now=arr[i].second;
        if(dp[now]==ans){
            ans--;
            lis_idx.push(i);
        }
    }
    for(int i=0;i<n;i++){
        if(lis_idx.size()){
            if(i==lis_idx.top()){
                lis_idx.pop();
                continue;
            }
        }
        cout<<arr[i].first<<'\n';
    }
}

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        arr.push_back({a,b});
    }
    sort(all(arr));
}

int main(){
    setup();
    input();
    solve();
}