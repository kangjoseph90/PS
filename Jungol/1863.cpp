#include <iostream>
using namespace std;

int n,m;

int parent[50001];

int find(int a){
    if(parent[a]==a) return a;
    return parent[a]=find(parent[a]);
}

int Union(int a,int b){
    a=find(a); b=find(b);
    if(a!=b) {
        parent[a]=b;
        return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) parent[i]=i;
    while(m--){
        int a,b; cin>>a>>b;
        n-=Union(a,b);
    }
    cout<<n;
}