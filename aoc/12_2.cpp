#include <bits/stdc++.h>

using namespace std;

int t;

map<string,int> node;
vector<string> node_name;

vector<vector<int>> edge;

vector<pair<string,string>> temp;

int visited[50];
bool twice=false;

pair<string,string> split(string &str,char key){
    string ret[2];
    int now=0;
    for(int i=0;i<str.length();i++){
        if(str[i]==key) now++;
        else ret[now].push_back(str[i]);
    }
    return {ret[0],ret[1]};
}

bool is_lower(string &str){
    for(auto item:str){
        if(item<'a') return false;
    }
    return true;
}

int solve(int now){
    if(node_name[now]=="end") return 1;
    int ret=0;
    for(auto next:edge[now]){
        bool lower=is_lower(node_name[next]);
        if(lower){
            if(visited[next]==2||(visited[next]==1&&twice)) continue;
            if(visited[next]==1) twice=true;
            visited[next]++;
            ret+=solve(next);
            visited[next]--;
            if(visited[next]==1)twice=false;
        }
        else{
            ret+=solve(next);
        }
    }
    return ret;
}


int main(){
    cin>>t;
    while(t--){
        string str;
        cin>>str;        
        pair<string,string> now=split(str,'-');
        node[now.first]=0;
        node[now.second]=0;
        temp.push_back(now);
    }
    int n=0;
    for(auto &item:node){
        node_name.push_back(item.first);
        item.second=n++;
    }
    edge.resize(n);
    for(auto &item:temp){
        int l=node[item.first],r=node[item.second];
        edge[l].push_back(r);
        edge[r].push_back(l);
    }
    visited[node["start"]]=2;
    cout<<solve(node["start"])<<endl;
}