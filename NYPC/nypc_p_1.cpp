#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

typedef long long ll;

ll n;

ll arr[1000001];

ll ans;

ll mn;

ll sum;

ll mx=LLONG_MIN;

bool t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        sum+=arr[i];
        mx=MAX(mx,arr[i]);
        mn=MIN(mn,sum);
        ans=MAX(ans,sum-mn);
    }
    if(mx>=0) cout<<ans;
    else cout<<mx;
}