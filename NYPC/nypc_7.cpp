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

//쿼리를 노드로 하는 그래프
//해당 색 위에 다른 색이 있으면, 그 색을 칠하는 쿼리에서 해당 쿼리로 향하는 간선이 생김
//위상정렬 후 역순으로 출력

struct query{
	int dir; //0~1 0-V, 1-H
	int idx,color; //1~100, 1~7
};

int n,m;
int board[110][110];

query int2query[30000];
vector<int> edge[30000];

vector<int> querylist;

int indegree[30000];

bool check[30000];

stack<int> sorted;

int query2int(query x){
	return x.color+x.idx*101+x.dir*101*101;
}

void initgraph(){
	for(int i=1;i<=n;i++){ //dir=0
		for(int j=1;j<=n;j++){
			if(!board[i][j]) continue;
			int now=query2int({0,j,board[i][j]});
			if(check[now]) continue;
			check[now]=true;
			int2query[now]={0,j,board[i][j]};
			querylist.push_back(now);
			for(int k=1;k<=n;k++){
				if(board[k][j]==board[i][j]||!board[k][j]) continue;
				int next=query2int({1,k,board[k][j]});
				int2query[next]={1,k,board[k][j]};
				edge[next].push_back(now);
				indegree[now]++;
			}
		}
	}
	for(int i=1;i<=n;i++){ //dir=1
		for(int j=1;j<=n;j++){
			if(!board[i][j]) continue;
			int now=query2int({1,i,board[i][j]});
			if(check[now]) continue;
			check[now]=true;
			int2query[now]={1,i,board[i][j]};
			querylist.push_back(now);
			for(int k=1;k<=m;k++){
				if(board[i][k]==board[i][j]||!board[i][k]) continue;
				int next=query2int({0,k,board[i][k]});
				int2query[next]={0,k,board[i][k]};
				edge[next].push_back(now);
				indegree[now]++;
			}
		}
	}
}

void topogical_sort(){
	queue<int> q;
	for(int i=0;i<querylist.size();i++)
		if(!indegree[querylist[i]])
			q.push(querylist[i]);
	while(q.size()){
		int now=q.front();
		q.pop();
		sorted.push(now);
		for(int i=0;i<edge[now].size();i++){
			int next=edge[now][i];
			if(!--indegree[next]) q.push(next);
		}
	}
}

void output(){
	cout<<sorted.size()<<'\n';
	while(sorted.size()){
		int now=sorted.top();
		sorted.pop();
		query ans=int2query[now];
		cout<<(ans.dir?"H ":"V ")<<ans.idx<<' '<<ans.color<<'\n';
	}
}

void input(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>board[i][j];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	initgraph();
	topogical_sort();
	output();
}