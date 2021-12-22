#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,k,x;
        cin>>n>>k>>x;
        string s;
        cin>>s;
        string temp;
        vector<ll> v;
        ll cnt=0;
        for(auto ch:s){
            if(ch=='a'){
                temp.push_back(ch);
                if(cnt) {
                    v.push_back(k*cnt);
                    cnt=0;
                }
            }
            if(ch=='*'){
                if(cnt==0) temp.push_back(ch);
                cnt++;
            }
        }
        if(cnt) v.push_back(k*cnt);
        vector<ll> ans;
        ans.resize(v.size());
        x--;
        for(int i=v.size()-1;i>=0;i--){
            ans[i]=x%(v[i]+1);
            x/=(v[i]+1);
        }
        ll idx=0;
        for(auto ch:temp){
            if(ch=='a') cout<<ch;
            else{
                for(int i=0;i<ans[idx];i++) cout<<'b';
                idx++;
            }
        }
        cout<<endl;
    }
}