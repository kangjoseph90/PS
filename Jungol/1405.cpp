#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int n;

int k[21]={0,1,};
int d[21]={0,1,};

int pow(int x){
    int ret=1;
    for(int i=0;i<x;i++) ret*=2;
    return ret;
}

void solve3(int from,int to,int banned,int top,int x){
    if(x==1){
        cout<<top<<" : "<<(char)(from+'A')<<"->"<<(char)(to+'A')<<'\n';
        return;
    }
    int empty=6-from-to-banned;
    solve3(from,empty,banned,top,x-1);
    cout<<top+x-1<<" : "<<(char)(from+'A')<<"->"<<(char)(to+'A')<<'\n';
    solve3(empty,to,banned,top,x-1);
}

void solve4(int from,int to,int top,int x){
    if(x==1){
        cout<<top<<" : "<<(char)(from+'A')<<"->"<<(char)(to+'A')<<'\n';
        return;
    }
    int temp;
    for(int i=0;i<4;i++){
        if(i!=from&&i!=to) {
            temp=i;
            break;
        }
    }
    solve4(from,temp,top,k[x]);
    solve3(from,to,temp,top+k[x],x-k[x]);
    solve4(temp,to,top,k[x]);
}

int fill_k(int x){
    if(k[x]) return d[x];
    int mn=pow(x);
    for(int i=1;i<x;i++){
        if(fill_k(i)*2+pow(x-i)-1<mn){
            mn=fill_k(i)*2+pow(x-i)-1;
            k[x]=i;
        }
    }
    return d[x]=mn;   
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin>>n;
    fill_k(n);
    cout<<d[n]<<'\n';
    solve4(0,3,1,n);
}