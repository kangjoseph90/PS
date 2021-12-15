#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n; 

pair<int,int> ans;

int f(int x){
    int ret=0;
    for(int i=0;i<n;++i){
        ret+=abs(v[i]-x);
    }
    return ret;
}

int solve(int e){
    int s=0;
    while(s<=e){
        int l=(2*s+e)/3,r=(s+2*e)/3;
        int fl=f(l),fr=f(r);
        if(fl>=fr) s=l+1;
        if(fr>=fl) e=r-1;
    }
    int ret=1e9;
    for(int i=e;i<=s;i++){
        ret=min(ret,f(i));
    }
    return ret;
}

int main(){
    cin>>n;
    int mx=0;
    for(int i=0;i<n;++i){
        int t; cin>>t;
        mx=max(mx,t);
        v.push_back(t);
    }
    cout<<solve(mx);
}