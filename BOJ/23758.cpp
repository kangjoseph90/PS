#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    priority_queue<int> pq;
    for(int i=0;i<(n+1)/2;i++){
        pq.push(v[i]);
    }
    

}