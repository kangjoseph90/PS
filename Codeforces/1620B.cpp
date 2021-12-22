#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int w,h;
        cin>>w>>h;
        long long ans=0;
        for(int i=0;i<2;i++){
            vector<int> v;
            int n;
            cin>>n;
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                v.push_back(x);
            }
            sort(v.begin(),v.end());
            ans=max(ans,(long long)h*(v.back()-v.front()));
        }
        for(int i=0;i<2;i++){
            vector<int> v;
            int n;
            cin>>n;
            for(int j=0;j<n;j++){
                int y;
                cin>>y;
                v.push_back(y);
            }
            sort(v.begin(),v.end());
            ans=max(ans,(long long)w*(v.back()-v.front()));
        }
        cout<<ans<<endl;
    }
}