#include <iostream>

using namespace std;

int t;
int n,m,k,d;

int main(){

    cin>>t;
    while(t--){
        cin>>n>>m>>k>>d;
        int c=(n*m*((m-1)*k+(n-1)*m))/2;
        int b=d/c;
        cout<<(b==0?-1:c*b)<<endl;
    }

}