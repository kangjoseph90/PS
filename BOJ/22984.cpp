#include <bits/stdc++.h>

using namespace std;

int n;
vector<double> p;
vector<double> p2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    
    for(int i=0;i<n;i++){
        double pn;
        cin>>pn;
        p.push_back(pn);

    }
    for(int i=1;i<n;i++){
        p2.push_back((1-p[i-1])*p[i]+p[i-1]*(1-p[i]));
    }
    double ans=0;
    for(auto item:p) ans+=item;
    for(auto item:p2) ans+=item;
    cout<<ans<<endl;
}