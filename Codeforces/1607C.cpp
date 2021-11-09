#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
        priority_queue<ll> pq;
        for(int i=0;i<n;i++){
            int t; cin>>t;
            pq.push(-t);
        }
        ll sum=0,mx=LLONG_MIN;
        while(pq.size()){
            ll now=-pq.top();
            pq.pop();
            mx=max(mx,now+sum);
            sum-=now+sum;
        }
        cout<<mx<<'\n';
    }

}