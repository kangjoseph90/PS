#include <bits/stdc++.h>

using namespace std;

#define int long long

string input,binary;

int depth;

int ans;

string hex2bin(char h){
    int value;
    if(h>='0'&&h<='9') value=h-'0';
    else if(h>='a'&&h<='f') value=10+h-'a';
    else value=10+h-'A';
    string ret;
    for(int i=3;i>=0;i--){
        ret.push_back(((value&(1<<i))!=0)+'0');
    }
    return ret;
}

string str2bin(string &str){
    string ret;
    for(auto ch:str){
        ret=ret.append(hex2bin(ch));
    }
    return ret;
}

int read(int idx,int length){  
    if(idx+length-1>=binary.length()) return -1;
    int ret=0;
    for(int i=idx;i<idx+length;i++){
        ret*=2;
        ret+=binary[i]-'0';
    }
    return ret;
}

struct packet{

    int start_idx,end_idx,version,value;
    bool is_literal,error;

    packet(int start){start_idx=start;error=false;}

    void read_literal(void){ //literal packet 정보 읽기
        for(int i=0;i<depth;i++){
            cout<<' ';
        }
        cout<<"literal"<<endl;
        if(!is_literal) return;
        int idx=start_idx+6;
        value=0;
        while(idx<binary.length()){
            value<<=4;
            value+=read(idx+1,4);
            if(binary[idx]=='0'){
                end_idx=idx+5;
                break;
            }        
            idx+=5;
        }
    }

    void read_operator(void){ //operator packet 정보 읽기
        for(int i=0;i<depth;i++){
            cout<<' ';
        }
        cout<<"operator"<<endl;
        depth++;
        if(is_literal) return;
        int length_type=read(start_idx+6,1);
        if(length_type==0){
            int length=read(start_idx+7,15);
            int idx=start_idx+22;
            while(idx<start_idx+22+length){
                packet sub_packet(idx);
                sub_packet.read_header();
                sub_packet.read_data();
                idx=sub_packet.end_idx;
            }
            end_idx=idx;
        }
        else if(length_type==1){ //sub packet의 개수가 주어진 
            int sub_packet_size=read(start_idx+7,11);
            int idx=start_idx+18;
            for(int i=0;i<sub_packet_size;i++){
                packet sub_packet(idx); //sub packet은 literal이다
                sub_packet.read_header();
                sub_packet.read_data();
                idx=sub_packet.end_idx;
            }
            end_idx=idx;
        }
        depth--;
    }

    void read_data(void){
        if(is_literal) read_literal();
        else read_operator();
    }

    void read_header(void){ //packet의 version, type(literal,operator) 읽기
        if(start_idx+11>=binary.length()){
            error=true;
        }
        version=read(start_idx,3);
        ans+=version;
        is_literal=(read(start_idx+3,3)==4);
    }

};


void solve(){  
    int idx=0;
    while(idx<binary.length()){
        packet now(idx);
        now.read_header();
        if(idx>5000) break;
        if(now.error) break;
        now.read_data();
        idx=now.end_idx;
    }
}




int32_t main(){
    cin>>input;
    binary=str2bin(input);
    cout<<binary<<endl;
    solve();
    cout<<ans<<endl;
}