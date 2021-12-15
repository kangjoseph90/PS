#include <bits/stdc++.h>

using namespace std;

char rule[100][100];

list<char> ans;

string temp;

pair<string,string> split(string &str){
    string ret[2];
    int now=0;
    for(auto ch:str){
        if(ch=='-') now++;
        else if(ch=='>') continue;
        else ret[now].push_back(ch);
    }
    return {ret[0],ret[1]};
}

void step(int cnt){
    for(auto iter=ans.begin();iter!=ans.end();iter++){
        auto iter_next=iter;
        iter_next++;
        if(iter_next==ans.end()) break;
        if(rule[*iter][*iter_next]){
            ans.insert(iter_next,rule[*iter][*iter_next]);
            iter++;
        }
    }
    //cout<<"step "<<cnt<<endl;
    //for(auto ch:ans){
    //    cout<<ch<<' ';
    //}
    //cout<<endl;
}

int main(){
    cin>>temp;
    for(auto ch:temp) ans.push_back(ch);

    int n;
    cin>>n;
    while(n--){
        cin>>temp;
        pair<string,string> now=split(temp);
        rule[now.first[0]][now.first[1]]=now.second[0];
    }

    for(int i=1;i<=10;i++) step(i);

    map<char,int> cnt;
    for(auto ch:ans){
        cnt[ch]++;
    }
    int mx=0,mn=1e9;
    for(auto item:cnt){
        mx=max(mx,item.second);
        mn=min(mn,item.second);
    }
    cout<<mx-mn<<endl;


}