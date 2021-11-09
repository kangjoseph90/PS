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
#include <cstdio>

#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
#define all(x) x.begin(),x.end()

using namespace std;

//무지성 dfs - O(n^2)
//한 정점에서 n개 정점 모두 방문할수 있다면 카운트

//dp로 최적화?
//노드 A에서 B로 갔을 때 B 아래의 노드 개수를 저장할수 있음



int n;

vector<int> edge[300001];

map<int,int> dp[300001];

int dfs(int last,int now){
	if(dp[last].find(now)!=dp[last].end()) return dp[last][now];
	int ret=1;
	for(int i=0;i<edge[now].size();i++){
		int next=edge[now][i];
		if(next==last) continue;
		int temp=dfs(now,next);
		dp[now][next]=temp;
		ret+=temp;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edge[a].push_back(b);
		if(!c) edge[b].push_back(a);
	}
	int ans=0;
	for(int i=1;i<=n;i++){	
		ans+=(dfs(0,i)==n);
	}
	cout<<ans;
}