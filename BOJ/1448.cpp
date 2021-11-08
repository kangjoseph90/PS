#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<int> v;


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int t; cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());

}