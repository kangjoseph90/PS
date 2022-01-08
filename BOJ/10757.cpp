#include <bits/stdc++.h>

using namespace std;

void f(string &s){
    string temp;
    for(int i=s.length()-1;i>=0;i--){
        temp.push_back(s[i]);
    }
    swap(temp,s);
}

int main(){
    string A,B,ans;
    cin>>A>>B;
    if(A.length()<B.length()) swap(A,B);
    f(A); f(B);
    int carry=0;
    for(int i=0;i<B.length();i++){
        if(A[i]+B[i]+carry-'0'>'9'){
            ans.push_back(A[i]+B[i]+carry-'0'-10);
            carry=1;
        }
        else {
            ans.push_back(A[i]+B[i]+carry-'0');
            carry=0;
        }
    }
    for(int i=B.length();i<A.length();i++){
        if(A[i]+carry>'9'){
            ans.push_back(A[i]+carry-10);
            carry=1;
        }
        else {
            ans.push_back(A[i]+carry);
            carry=0;
        }
    }
    if(carry) ans.push_back('1');
    f(ans);
    cout<<ans<<endl;
}