#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
#define double long double
int n,k;
int d[4];

vector<int> card[4];
int idx[4]={0,};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<4;i++) cin>>d[i];
    for(int i=0;i<n;i++){
        char ch; int t; 
        cin>>ch>>t;
        card[ch-'A'].push_back(-t);
    }
    for(int i=0;i<4;i++){
        sort(card[i].begin(),card[i].end());
    }
    while(k--){
        int argmx=-1;
        for(int i=0;i<4;i++){
            if(idx[i]>=card[i].size()) continue;
            if(argmx==-1){
                argmx=i;
                continue;
            }
            if(-card[i][idx[i]]*d[argmx]>=-card[argmx][idx[argmx]]*d[i]) argmx=i;
        }
        cout<<(char)(argmx+'A')<<' '<<-card[argmx][idx[argmx]]<<'\n'; 
        d[argmx]-=card[argmx][idx[argmx]++];
    }
}