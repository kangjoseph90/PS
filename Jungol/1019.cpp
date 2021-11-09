#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define MAX(x,y) (x>y?x:y)

int arr[50010];

int sum[50010];

int dp[3][50010];

int tree[3][200010];

int n,k;

int init(int idx,int l,int r,int node){
    if(l==r) return tree[idx][node]=dp[idx][l];
    int m=(l+r)/2;
    int left=init(idx,l,m,node*2);
    int right=init(idx,m+1,r,node*2+1);
    return tree[idx][node]=MAX(left,right);
}

int find(int idx,int l,int r,int node,int s,int e){
    if(l>e||r<s) return 0;
    if(l>=s&&r<=e) return tree[idx][node];
    int m=(l+r)/2;
    int left=find(idx,l,m,node*2,s,e);
    int right=find(idx,m+1,r,node*2+1,s,e);
    return MAX(left,right);
}

int solve(){
    for(int idx=0;idx<3;idx++){
        for(int i=k;i<=n;i++){
            int now=sum[i]-sum[i-k];
            dp[idx][i]=now;
            if(idx){
                int temp=find(idx-1,1,n,1,1,i-k);
                dp[idx][i]+=temp;
            }
        }
        init(idx,1,n,1);
    }
    return find(2,1,n,1,1,n);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    cin>>k;
    for(int i=1;i<=n;i++) {
        sum[i]=arr[i]+sum[i-1];
    }
    cout<<solve();
}