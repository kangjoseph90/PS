#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
using namespace std;

int str2int(string s){
    int ret=0;
    for(int i=0;i<s.length();i++){
        ret=ret*2+s[i]-'0';
    }
    return ret;
}


int i;
char mn,mx;

int main(){
    string t;
    list<string> ox,co;
    while(!cin.eof()){
        cin>>t;
        ox.push_back(t);
        co.push_back(t);
    }
    for(i=0;i<12;i++){
        if(ox.size()>1){
            int ox_cnt[2];
            ox_cnt[0]=ox_cnt[1]=0;
            for(auto &item:ox){
                ox_cnt[item[i]-'0']++;
            }
            mx=(ox_cnt[0]>ox_cnt[1]?'0':'1');
            ox.remove_if([](string &s){return s[i]!=mx;});
        }
        if(co.size()>1){
            int co_cnt[2];
            co_cnt[0]=co_cnt[1]=0;
            for(auto &item:co){
                co_cnt[item[i]-'0']++;
            }
            mn=(co_cnt[0]<=co_cnt[1]?'0':'1');
            co.remove_if([](string &s){return s[i]!=mn;});
        }
    }
    cout<<str2int(ox.front())*str2int(co.front());
}