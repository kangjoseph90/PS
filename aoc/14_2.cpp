#include <bits/stdc++.h>

using namespace std;

#define int long long

int ans[100][100];

char rule[100][100];

string temp,input;

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
    int ans_temp[100][100]={0,};
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(rule[i][j]){
                ans_temp[i][rule[i][j]]+=ans[i][j];
                ans_temp[rule[i][j]][j]+=ans[i][j];
            }
            else ans_temp[i][j]=ans[i][j];
        }
    }
    swap(ans_temp,ans);
    //cout<<cnt<<endl;
    //for(int i=0;i<100;i++){
    //    for(int j=0;j<100;j++){
    //        if(ans[i][j]){
    //            cout<<(char)i<<' '<<(char)j<<" : "<<ans[i][j]<<endl;
    //        }
    //    }
    //}
}

int32_t main(){
    cin>>input;
    for(int i=0;i+1<input.length();i++){
        ans[input[i]][input[i+1]]++;
    }

    int n;
    cin>>n;
    while(n--){
        cin>>temp;
        pair<string,string> now=split(temp);
        rule[now.first[0]][now.first[1]]=now.second[0];
    }

    for(int i=1;i<=40;i++) step(i);
    int cnt[100]={0,};
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            cnt[i]+=ans[i][j];
            cnt[j]+=ans[i][j];
        }
    }
    cnt[input.front()]++;
    cnt[input.back()]++;
    int mx=0,mn=1e18;
    for(int i=0;i<100;i++){
        mx=max(mx,cnt[i]);
        if(cnt[i]) mn=min(mn,cnt[i]);
    }
    cout<<(mx-mn)/2<<endl;
}