#include <bits/stdc++.h>

using namespace std;

typedef long long ll;




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> cnt(n+1);
        for(int i=0;i<n;i++){
            int a;cin>>a;
            cnt[a]++;
        }
        stack<pair<int,int>> s;
        int op_cnt=0;
        bool err=false;
        cout<<cnt[0]<<' ';
        for(int i=1;i<=n;i++){
            if(err){
                cout<<-1<<' ';
                continue;
            }
            if(cnt[i-1]==0){
                if(s.empty()){
                    cout<<-1<<' ';
                    err=true;
                    continue;
                } 
                else{
                    pair<int,int> now=s.top();
                    s.pop();
                    op_cnt+=i-1-now.first;
                    if(now.second>1) s.push({now.first,now.second-1});
                }
            }
            else if(cnt[i-1]>1){
                s.push({i-1,cnt[i-1]-1});
            }
            cout<<op_cnt+cnt[i]<<' ';
        }
        cout<<endl;

    }

}