#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
    int t;
    cin>>t;
    while(t--){
        string a,temp;
        vector<int> v;
        cin>>a>>temp;
        int i=a.length()-1,j=temp.length()-1;
        bool done=true;
        for(;i>=0&&j>=0;i--,j--){
            if(a[i]>temp[j]){
                v.push_back(temp[j]+10-a[i]);
                j--;
                if(temp[j]!='1'){
                    done=false;
                }
            } 
            else{
                v.push_back(temp[j]-a[i]);
            }
        }
        if(i>=0||!done||j<-1){
           cout<<-1<<endl; 
           continue;
        } 
        while(j>=0) v.push_back(temp[j--]-'0');
        bool start=true;
        for(int i=v.size()-1;i>=0;i--){
            if(start&&v[i]==0) continue;
            if(v[i]!=0) start=false;
            cout<<v[i];
        }
        if(start) cout<<-1;
        cout<<endl;
    }

}