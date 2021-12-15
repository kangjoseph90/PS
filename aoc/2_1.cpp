#include <iostream>
#include <string>

using namespace std;

int main(){
    int x,y;
    x=y=0;
    string s;
    int t;
    while(!cin.eof()){
        cin>>s>>t;
        if(s=="forward") x+=t;
        else if(s=="up") y-=t;
        else y+=t;
    }
    cout<<x*y;


}