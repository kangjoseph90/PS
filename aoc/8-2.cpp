#include <bits/stdc++.h>

using namespace std;

int key[7]={716,166,3936,211,36,3941,91}; //각 segment의 key

set<int> cmp[10]={ 
    {0,1,2,4,5,6}, //0
    {2,5}, //1
    {0,2,3,4,6}, //2
    {0,2,3,5,6}, //3
    {1,2,3,5}, //4
    {0,1,3,5,6}, //5
    {0,1,3,4,5,6}, //6
    {0,2,5}, //7
    {0,1,2,3,4,5,6}, //8
    {0,1,2,3,5,6}
int matched[7];


void match(vector<string> &sample){
    int cnt[7][8];
    for(int i=0;i<7;i++)
        for(int j=0;j<8;j++) cnt[i][j]=0;
    for(int i=0;i<7;i++){
        for(int j=0;j<10;j++){
            if(sample[j].find(i+'a')!=string::npos){
                cnt[i][sample[j].length()]++;
            }
        }
    }
    for(int i=0;i<7;i++){
        int key_temp=0;
        for(int j=0;j<8;j++){
            key_temp*=5;
            key_temp+=cnt[i][j];
        }
        for(int j=0;j<7;j++){
            if(key_temp==key[j]) matched[i]=j;
        }
    }
}


int main(){
    int t;
    cin>>t;
    int ans=0;
    while(t--){
        vector<string> sample;
        for(int i=0;i<10;i++){
            string temp;
            cin>>temp;
            sample.push_back(temp);
        }
        match(sample);
        int sum=0;
        for(int i=0;i<4;i++){
            string temp;
            cin>>temp;
            set<int> num;
            for(auto ch:temp){
                num.insert(matched[ch-'a']);
            }
            for(int j=0;j<10;j++){
                if(cmp[j]==num) {
                    sum*=10;
                    sum+=j;
                    break;
                }
            }
        }
        ans+=sum;
    }
    cout<<ans<<endl;



}