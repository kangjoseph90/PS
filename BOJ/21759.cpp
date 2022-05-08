#include <iostream>
#include <vector>

using namespace std;

#define int long long

const int LIM=200001;

int N;


vector<int> edge[LIM];
int arr[LIM],dp[LIM];

vector<int> ans;

int32_t main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        int a,p;
        cin>>a>>p;
        arr[i]=a;
        if(p==-1) continue;
        edge[p].push_back(i);
    }
}