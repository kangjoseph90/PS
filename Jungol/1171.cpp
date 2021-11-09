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

#define int long long

void setup(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int N;
int n=-1; //N - n자리수
int a,b,c;

int p[20];

vector<pair<int,int>> ans;

int pow(int x){
	if(p[x]) return p[x];
	int ret=1;
	while(x--) ret*=10;
	return p[x]=ret;
}

void solve(){
	for(int c=0;c<10;c++){
		for(int k=0;k<=n;k++){
			int now=N-c*pow(k); //now=11*a*10^k+2b
			if(now<0) continue;
			for(b=now%(11*pow(k));b<2*pow(k)&&b<=now;b+=11*pow(k)){
				if(b%2) continue;
				a=(now-b)/(11*pow(k));
				if(c==0&&a==0) continue;
				ans.push_back({a*pow(k+1)+c*pow(k)+b/2,a*pow(k)+b/2});
			}
		}
	}
}

int cnt(int x){
	if(x==0) return 1;
	int ret=0;
	while(x){
		ret++;
		x/=10;
	}
	return ret;
}

int32_t main(){
    cin>>N;
	for(int i=1;N/i;i*=10) n++;
	solve();
	sort(all(ans));
	int size=!ans.empty();
	for(int i=1;i<ans.size();i++){
		if(ans[i].first!=ans[i-1].first) size++;
	}
	cout<<size<<'\n';
	for(int i=0;i<ans.size();i++) {
		if(i) if(ans[i].first==ans[i-1].first) continue;
		int l=cnt(ans[i].first);
		int r=cnt(ans[i].second);
		cout<<ans[i].first<<" + ";
		for(int i=0;i<l-r-1;i++) cout<<0;
		cout<<ans[i].second<<" = "<<N<<'\n';
	}
}