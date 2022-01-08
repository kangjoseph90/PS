#include <bits/stdc++.h>

using namespace std;
int n,cnt2,cnt5;
int main(){
    cin>>n;
    for(int i=2;i<=n;i++){
        int temp=i;
        while(!(temp%2)){
            temp/=2;
            cnt2++;
        }
        temp=i;
        while(!(temp%5)){
            temp/=5;
            cnt5++;
        }
    }
    cout<<min(cnt2,cnt5)<<endl;

}