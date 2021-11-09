#include <iostream>
#include <string>

using namespace std;


string a,b;


int compare(int a_idx){
    if(a_idx+b.length()-1>=a.length()) return -1;
    for(int i=0;i<a_idx;i++) if(a[i]>'0') return 1;
    for(int i=0;i<b.length();i++){
        if(a[a_idx+i]<b[i]) return 0;
        if(a[a_idx+i]>b[i]) return 1;
    }
    return 1;
}

void reduce(int a_idx){
    int carry=0;
    for(int i=b.length()-1;i>=0;i--){
        if(a[i+a_idx]-b[i]-carry<0){
            a[i+a_idx]='0'+10+a[i+a_idx]-b[i]-carry;
            carry=1;
        }
        else{
            a[i+a_idx]='0'+a[i+a_idx]-b[i]-carry;
            carry=0;
        }
    }
    for(int i=a_idx-1;i>=0&&carry;i--){
        if(a[i]>'0') {
            a[i]--;
            carry=0;
        }
        else{
            a[i]='9';
            carry=1;
        }
    }
}

void solve(){
    string ans;
    int len=b.length();
    bool t=false;
    for(int i=0;i<a.length();i++){
        char now='0';
        int val;
        while(true){
            val=compare(i);
            if(val!=1) break;
            reduce(i);
            now++;
        }
        if(now!='0') t=true;
        if(val==0&&t) ans.push_back(now);
        //cout<<"a : "<<a<<" b : "<<b<<'\n';
    }
    cout<<ans<<'\n';

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<a;
    while(true){
        cin>>a>>b;
        if(a.length()<b.length()) swap(a,b);
        else if(a.length()==b.length()){
            if(!compare(0)) swap(a,b);

        }
        if(a=="0"||b=="0") break;
        solve();
    }


}