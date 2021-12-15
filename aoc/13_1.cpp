#include <bits/stdc++.h>

using namespace std;

int t,n;

set<pair<int,int>> s;

pair<int,int> split(string &str){
    string ret[2];
    int now=0;
    for(auto ch:str){
        if(ch==',') now++;
        else ret[now].push_back(ch);
    }
    return {stoi(ret[0]),stoi(ret[1])};
}


int main(){
    cin>>t;
    while(t--){
        string str;
        cin>>str;   
        pair<int,int> now=split(str);
        s.insert(now);
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        char dir;
        int idx;
        cin>>dir>>idx;
        pair<int,int> axis;
        if(dir=='y') axis={3000,idx};
        else axis={idx,3000};
        set<pair<int,int>> temp;
        //cout<<"----"<<i<<"----"<<endl;
        for(auto item:s){
            //cout<<item.first<<' '<<item.second<<" -> ";
            pair<int,int> flip;
            if(item.first==axis.first||item.second==axis.second) continue;
            if(item.first<axis.first) flip.first=item.first;
            else flip.first=2*axis.first-item.first;
            if(item.second<axis.second) flip.second=item.second;
            else flip.second=2*axis.second-item.second;
            //cout<<flip.first<<' '<<flip.second<<endl;
            temp.insert(flip);
        }
        swap(s,temp);
        if(i==1) cout<<s.size()<<endl;
    }
    //cout<<s.size()<<endl;



}