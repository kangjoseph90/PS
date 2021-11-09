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

int n, m;

int arr[2001];

bool visited[2001][2001];

set<int> alive;


void solve(int start, int cnt) {
	vector<int> cycle;
	vector<int> v;
	if (cnt == 1) {
		cout << *alive.begin();
		return;
	}
	for (auto iter = alive.begin(); iter != alive.end(); iter++) {
		v.push_back(*iter);
	}
	int now = lower_bound(all(v), start) - v.begin() - 1;
	now = (now + m % cnt + cnt) % cnt; //v 에서의 인덱스
	int mn = INT_MAX;
	int mnidx = -1;
	while (true) {
		if (visited[cnt][now] == true) break;
		visited[cnt][now] = true;
		cycle.push_back(now);
		if (arr[v[now]] < mn) {
			mn = arr[v[now]];
			mnidx = now;
		}
		now = (now + m % cnt) % cnt;
	}
	int s = 0;
	for (int i = 0; i < cycle.size(); i++) {
		arr[v[cycle[i]]] -= mn;
		arr[v[cycle[i]]] += s;
		if (cycle[i]==mnidx) s++;
	}
	//cout << v[mnidx] << '\n';
	//for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
	//cout << endl;
	auto iter = alive.find(v[mnidx]);
	alive.erase(iter);
	solve(v[mnidx], cnt - 1);
}

int main() {
	fastio();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		alive.insert(i);
	}
	solve(0, n);
}