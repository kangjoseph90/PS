#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//하위에서부터 개수를 파악하는게 유리할까 ? ? ? 
//left 기준으로 sort -> right의 LDS 문제로 됨

//lines[i]==lines[j]일때의 관계가 정의되지 않음

#define MAX(x,y) (x>y?x:y);

vector<pair<int,int>> lines; 

vector<int> rightv;

int n;

int dp[500010];

int tree[2000010]; //max segment tree

bool compare(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}

int update(int l,int r,int node,int idx,int val){
    if(l>idx||r<idx) return tree[node];
    if(l==r) return tree[node]=MAX(tree[node],val);
    int m=(l+r)/2;
    int L=update(l,m,node*2,idx,val);
    int R=update(m+1,r,node*2+1,idx,val);
    return tree[node]=MAX(L,R);
}

int find(int l,int r,int node,int s,int e){
    if(l>e||r<s) return 0;
    if(l>=s&&r<=e) return tree[node];
    int m=(l+r)/2;
    int L=find(l,m,node*2,s,e);
    int R=find(m+1,r,node*2+1,s,e);
    return MAX(L,R);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) {
        int x,l,r; cin>>x>>l>>r;
        lines.push_back({l,r});
        rightv.push_back(r);
    }
    sort(lines.begin(),lines.end(),compare);
    sort(rightv.begin(),rightv.end());
    rightv.erase(unique(rightv.begin(),rightv.end()),rightv.end());
    int ans=0;
    for(int i=0;i<n;i++){
        int r_idx=lower_bound(rightv.begin(),rightv.end(),lines[i].second)-rightv.begin()+1;
        dp[i]=find(1,n,1,r_idx,n)+1;
        if(i) if(lines[i].first==lines[i-1].first&&lines[i].second==lines[i-1].second) dp[i]--;
        update(1,n,1,r_idx,dp[i]);
        ans=MAX(dp[i],ans);
    }
    cout<<ans;
}