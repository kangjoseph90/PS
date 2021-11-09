#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <list>
#include <climits>
#include <cstdlib>
#include <cmath>

#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define all(x) x.begin(),x.end()

#define ll long long
#define pii pair<int,int>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
};

void precision(int x) {
	cout << fixed;
	cout.precision(x);
}

int norm(int x) {
	return MAX(x, -x);
}

bool visited[2001][2001];

vector<int> cycle[2001];

int n, m;

int arr[2001];

int alive[2001];

int tree[10000];

int init(int s, int e, int node) {
	if (s == e) return tree[node] = alive[s];
	int m = (s + e)>>1;
	return tree[node] = init(s, m, node<<1) + init(m + 1, e, (node<<1) + 1);
}

int update(int s, int e, int node, int idx) {
	if (s > idx || e < idx) return tree[node];
	if (s == e) return tree[node] = alive[s] = 0;
	int m = (s + e) >>1;
	return tree[node] = update(s, m, node<<1, idx) + update(m + 1, e, (node<<1) + 1, idx);
}

int sum(int s, int e, int node, int l, int r) {
	if (l > r) return 0;
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tree[node];
	int m = (s + e)>>1;
	return sum(s, m, node<<1, l, r) + sum(m + 1, e, (node<<1) + 1, l, r);
}

//cnt 개 남았을때, 사이클 탐색
//세그트리로 다음사람 찾기
//사이클에서 최소인 사람꺼 만큼 낮추고, cnt--

int find_next(int start,int end,int togo) {
	//cout << "start:" << start << " togo:" << togo << '\n';
	int l = start + 1, r = n;
	int ret=start;
	while (l <= r) {
		int m = (l + r)>>1;
		int now = sum(1, n, 1, start + 1, m);
		//cout << "m:" << m << " now:" << now << '\n';
		if (now == togo) {
		    if(!alive[m]){
		        r=m-1;
		        continue;
		    }
			ret = m;
			break;
		}
		else if (now > togo) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return ret;
}

void solve(int now, int cnt) {
	int right = sum(1, n, 1, now + 1, n);
	int togo = m % cnt;
	if (togo == 0) togo = cnt;
	if (togo <= right)
		now = find_next(now,n, togo);
	else
		now = find_next(0,now, togo - right);
	if (cnt == 1) {
		cout << now;
		return;
	}
	int mn = INT_MAX;
	int mnidx = -1;
	while (true) {
		if (visited[cnt][now] == true) break;
		visited[cnt][now] = true;
		cycle[cnt].push_back(now);
		if (arr[now] < mn) {
			mn = arr[now];
			mnidx = now;
		}
		if (arr[now] == 1) break;
		//cout << now<<' ';
		right = sum(1, n, 1, now + 1, n);
		togo = m % cnt;
		if (togo == 0) togo = cnt;
		if (togo <= right) 
			now = find_next(now,n, togo);
		else 
			now = find_next(0,now, togo - right);
	}
	//cout << endl;
	
	int s = 0;
	//cout << mnidx << '\n';
	for (int i = 0; i < cycle[cnt].size(); i++) {
		arr[cycle[cnt][i]] -= mn;
		arr[cycle[cnt][i]] += s;
		if (cycle[cnt][i] == mnidx) s++;
	}
	//cout << "arr:";
	//for (int i = 1; i <= n; i++) cout << arr[i] <<  ' ';
	//cout << endl;
	update(1, n, 1, mnidx);
	solve(mnidx, cnt - 1);
}

int main() { 
	fastio();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		alive[i] = 1;
	}
	init(1, n, 1);
	solve(0,n);
	
}