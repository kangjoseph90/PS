#include <bits/stdc++.h>

using namespace std;

typedef long long ll;




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n; //v2[i] i번째 사람의 각 가게에 대한 가격
        vector<vector<ll>> v(m),v2(n); //v[i] i번째 가게가 갖고 있는 각 사람에 대한 가격
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ll p;
                cin>>p;
                v[i].push_back(p);
                v2[j].push_back(p);
            }
        }
        for(int i=0;i<n;i++) sort(v2[i].begin(),v2[i].end());
        ll mn=LLONG_MAX;
        for(int i=0;i<m;i++){
            ll now=0;
            for(int j=0;j<n;j++){
                if(v[i][j]==v2[j][0]){
                    now+=v2[j][1];
                }
                else now+=v2[j][0];
            }
            mn=min(mn,now);
        }
        cout<<mn<<endl;
    }

}