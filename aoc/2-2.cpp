#include <iostream>
#include <string>

using namespace std;

int main(){
    int x,y,a;
    x=y=0;
    string s;
    int t;
    while(!cin.eof()){
        cin>>s>>t;
        if(s=="forward") {
            x+=t;
            y+=a*t;
        }
        else if(s=="up") a-=t;
        else a+=t;
    }
    cout<<x*y;


}