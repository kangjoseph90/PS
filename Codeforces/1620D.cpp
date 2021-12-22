#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int min_arr(int arr[],int len){
    int ret=INT_MAX;
    for(int i=0;i<len;i++){
        ret=min(ret,arr[i]);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v;
        bool have_one=false;
        int cnt[3]={0,};
        for(int i=0;i<n;i++){
            int x; cin>>x;
            v.push_back(x);
            if(x==1) have_one=true;
            cnt[x%3]++;
        } 
        int ans=0;
        if(cnt[2]){
            if(have_one){ //1,2 
                for(auto item:v) ans=max(ans,item/3+2-(item%3==0));
            }
            else if(cnt[1]){ //1,2 2,2 2,2,2
                int ans_t[3]={0,};
                for(auto item:v){
                    ans_t[0]=max(ans_t[0],item/3+2-(item%3==0));
                    ans_t[1]=max(ans_t[1],item/3+2-(item%3==1));
                    ans_t[2]=max(ans_t[2],item/3+3-(item%3==0)*2-(item%3==1));
                }
                ans=min_arr(ans_t,3);
            }
            else{
                for(auto item:v) ans=max(ans,item/3+1);
            }
        }
        else{
            if(cnt[1]){
                for(auto item:v) ans=max(ans,item/3+1);
            
            }
            else{
                for(auto item:v) ans=max(ans,item/3);
                
            }
        }
        cout<<ans<<endl;
    }
}