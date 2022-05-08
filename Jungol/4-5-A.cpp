#include <iostream>

using namespace std;

long long n,k;

long long sum;

int main(){
    cin>>n;
    for(k=1;k<1800;k++){
        if(k*(k+1)/2>n){
            k--;
            break;
        }
    }
    sum=k*(k+1)*(2*k+1)/6;
    for(int i=k*(k+1)/2+1;i<=n;i++){
        sum+=k+1;
    }
    cout<<sum;
}