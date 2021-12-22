#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define all(x) x.begin(),x.end()

int n;

vector<long long> A,B;

vector<long long> v;

int f(int idx,int ai){
    if(idx>ai) return INT_MAX;
    return A[idx];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    A.resize(n+1); B.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>A[i];
        v.push_back(A[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>B[i];
        v.push_back(B[i]);
    } 
    v.push_back(INT_MAX);
    sort(all(v));
    int q;
    cin>>q;
    while(q--){
        int ai,bi,k;
        cin>>ai>>bi>>k;
        int s=0,e=v.size();
        int acnt,bcnt;
        while(s<=e){
            int m=(s+e)/2;
            acnt=min((int)(lower_bound(all(A),v[m])-A.begin()-1),ai);
            bcnt=min((int)(lower_bound(all(B),v[m])-B.begin()-1),bi);
            if(acnt+bcnt==k){
                break;
            }
            else if(acnt+bcnt>k){
                e=m-1;
            }
            else s=m+1;
        }
        if(A[acnt]>B[bcnt]){
            cout<<"1 "<<acnt<<endl;
        }
        else cout<<"2 "<<bcnt<<endl;

    }
}