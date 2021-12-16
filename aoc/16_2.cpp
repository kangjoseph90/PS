#include <bits/stdc++.h>

using namespace std;

#define int long long

string input,binary;

int depth;

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

int get_value(vector<int> &sub_values, int type_id){ //operator packet의 value 계산
    switch(type_id){
        case 0:{
            int ret=0;
            for(auto item:sub_values) ret+=item;
            return ret;
            break;
        }
        case 1:{
            int ret=1;
            for(auto item:sub_values) ret*=item;
            return ret;
            break;
        }
        case 2:{
            int ret=LLONG_MAX;
            for(auto item:sub_values) ret=min(ret,item);
            return ret;
            break;
        }
        case 3:{
            int ret=LLONG_MIN;
            for(auto item:sub_values) ret=max(ret,item);
            return ret;
            break;
        }
        case 5:{
            return (int)(sub_values[0]>sub_values[1]);
            break;
        }
        case 6:{
            return (int)(sub_values[0]<sub_values[1]);
            break;
        }
        case 7:{
            return (int)(sub_values[0]==sub_values[1]);
            break;
        }
    }
    return -1;
}

struct packet{

    int start_idx,end_idx,version,value;
    bool is_literal,error;
    int type_id;

    packet(int start){start_idx=start;error=false;}

    void read_literal(void){ //literal packet 정보 읽기

        for(int i=0;i<depth;i++) cout<<' '; //패킷의 구조 출력 (tree 형태)
        cout<<"literal "<<type_id<<endl;

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
        
        for(int i=0;i<depth;i++) cout<<' '; //패킷의 구조 출력 (tree 형태)
        cout<<"operator "<<type_id<<endl; 
        depth++;

        int length_type=read(start_idx+6,1);
        
        vector<int> sub_values;

        if(length_type==0){
            int length=read(start_idx+7,15);
            int idx=start_idx+22;
            while(idx<start_idx+22+length){
                packet sub_packet(idx);
                sub_packet.read_header();
                sub_packet.read_data();
                sub_values.push_back(sub_packet.value);
                idx=sub_packet.end_idx;
            }
            end_idx=idx;
        }

        else if(length_type==1){ //sub packet의 개수가 주어진 
            int sub_packet_size=read(start_idx+7,11);
            int idx=start_idx+18;
            for(int i=0;i<sub_packet_size;i++){
                packet sub_packet(idx); 
                sub_packet.read_header();
                sub_packet.read_data();
                sub_values.push_back(sub_packet.value);
                idx=sub_packet.end_idx;
            }
            end_idx=idx;
        }

        value=get_value(sub_values,type_id);

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
        type_id=read(start_idx+3,3);
        is_literal=(type_id==4);
    }

};


void solve(){  
    packet now(0);
    now.read_header();
    now.read_data();
    cout<<now.value<<endl;
}




int32_t main(){
    cin>>input;
    binary=str2bin(input);
    //cout<<binary<<endl;
    solve();
}