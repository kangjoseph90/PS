#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct aa{
    int cost,a,b;
}aa;

int parent[101];

int _find(int a){
    if(parent[a]==a) return a;
    return parent[a]=_find(parent[a]);
}

void Union(int a,int b){
    a=_find(a); b=_find(b);
    parent[a]=b;
}


int edge[101][101];
int n;

int ans;

vector<aa> v;

bool compare(aa a, aa b){
    return a.cost<b.cost;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        parent[i]=i;
        for(int j=1;j<=n;j++) cin>>edge[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            v.push_back({edge[i][j],i,j});
        }
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        if(_find(v[i].a)!=_find(v[i].b)){
            ans+=v[i].cost;
            Union(v[i].a,v[i].b);
        }
    }
    cout<<ans;
}   