#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int ans=-1;

vector<int> v;


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int t; cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    for(int i=2;i<n;i++){
        if(v[i-2]+v[i-1]>v[i]){
            ans=max(ans,v[i-2]+v[i-1]+v[i]);
        }
    }
    cout<<ans<<'\n';

}