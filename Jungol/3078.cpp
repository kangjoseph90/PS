#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
#define all(x) x.begin(),x.end()
using namespace std;

void setup(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

typedef struct aa{
    int first,second,cnt;
}aa;

int l,r, l_goal,r_goal;

set<pair<int,int>> visited;

queue<aa> q;

void bfs(){
    q.push({0,0});
    while(q.size()){
        aa now=q.front();
        q.pop();
        if(now.first==l_goal&&now.second==r_goal){
            cout<<now.cnt;
            return;
        }
        vector<pair<int,int>> todo;
        todo.push_back({0,now.second});
        todo.push_back({now.first,0});
        todo.push_back({(now.first+now.second>r?now.first+now.second-r:0),(now.first+now.second>r?r:now.first+now.second)});
        todo.push_back({(now.first+now.second>l?l:now.first+now.second),(now.first+now.second>l?now.first+now.second-l:0)});
        todo.push_back({now.first,r});
        todo.push_back({l,now.second});
        for(int i=0;i<todo.size();i++){
            pair<int,int> next=todo[i];
            if(visited.find(next)==visited.end()){
                visited.insert(next);
                q.push({next.first,next.second,now.cnt+1});
            }
        }
    }
    cout<<-1;
}

int main(){
    setup();
    cin>>l>>r>>l_goal>>r_goal;
    bfs();
}