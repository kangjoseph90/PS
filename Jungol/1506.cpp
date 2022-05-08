#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m,n;

struct plate{
    int x;
    int idx, ymn,ymx;
};

vector<plate> v;

vector<int> ans;

int sum[1001];

bool compare(plate& a,plate& b){
    if(a.x>b.x) return false;
    return true;
}

int main(){
    cin.sync_with_stdio(false);
    cin>>m>>n;
    for(int i=0;i<n;i++){
        plate temp;
        cin>>temp.idx>>temp.x>>temp.ymn>>temp.ymx;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),compare);
    for(auto item:v){
        //cout<<item.x<<endl;
        for(int i=item.ymn;i<item.ymx;i++){
            sum[i]++;
        }
        int mn=51;
        for(int i=item.ymn;i<item.ymx;i++){
            mn=min(sum[i],mn);
        }
        if(mn>m) ans.push_back(item.idx);
    }
    sort(ans.begin(),ans.end());
    for(auto item:ans) cout<<item<<' ';
    if(ans.empty()) cout<<0;
    return 0;
}