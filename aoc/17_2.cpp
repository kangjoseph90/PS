#include <bits/stdc++.h>

using namespace std;

#define int long long

struct interval{
    int l,r;
    bool in(int x){
        return l<=x&&x<=r;
    }
};

interval X,Y;

int get_max_height(int v_x){
    interval now={INT_MAX,INT_MAX}; //x좌표가 목표 안에 있는 시간의 구간
    int pos=0;
    for(int i=1;true;i++){
        pos+=v_x;
        v_x=max((long long)0,v_x-1);
        if(X.in(pos)){
            now.l=min(i,now.l);
        } 
        else if(now.l<now.r){
            now.r=i-1;
            break;
        }
        if(v_x==0) break;
    }
    //cout<<now.l<<' '<<now.r<<endl;
    int ret=INT_MIN;
    for(int i=0;i<1000;i++){
        bool check=false;
        for(int j=now.l;j<=now.r;j++){
            int y=j*i-j*(j-1)/2;
            if(Y.in(y)){
                check=true;
                break;
            } 
            else if(y<Y.l) break;
        }
        if(check){
            if(i>0) ret=max(ret,i*(i+1)/2);
            else ret=max(ret,(long long)0);
        }
    }
    return ret;
}

int32_t main(){
    cin>>X.l>>X.r>>Y.l>>Y.r;
    int ans=0;
    for(int i=0;i<1000;i++){
        ans=max(ans,get_max_height(i));
    }
    cout<<ans<<endl;
}