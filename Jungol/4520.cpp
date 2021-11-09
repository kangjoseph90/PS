#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n,k;

string str;
vector<int> h,p;

int h_idx,p_idx;

int ans;

int abs(int a,int b){
    return a>b?a-b:b-a;
}

int main(){
    cin>>n>>k;
    cin>>str;
    for(int i=0;i<n;i++){
        if(str[i]=='H') h.push_back(i);
        else p.push_back(i);
    }
    for(p_idx;p_idx<p.size();p_idx++){
        if(h_idx>=h.size()) break;
        if(h[h_idx]>p[p_idx]+k) continue;
        else if(h[h_idx]<p[p_idx]-k){
            h_idx=lower_bound(h.begin(),h.end(),p[p_idx]-k)-h.begin();
            p_idx--;
        }
        else{
            h_idx++;
            ans++;
        }
    }
    cout<<ans;
}