#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;

    cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i]!=str[str.length()-i-1]){
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<1<<endl;
    return 0;

}