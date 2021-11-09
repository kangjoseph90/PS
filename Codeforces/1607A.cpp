#include <iostream>
#include <vector>
#include <string>

using namespace std;

int val[256];

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        for(int i=1;i<=26;i++){
            char c; cin>>c;
            val[c]=i;
        }
        cin>>s;
        int ans=0;
        for(int i=1;i<s.length();i++){
            ans+=abs(val[s[i]]-val[s[i-1]]);
        }
        cout<<ans<<'\n';

    }

}