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

//1번 선부터 연결
//교차할 수 있는 선이 n개다 -> ans+=n+1

//교차판정? ->O(n)
//전체 O(n^2)

//하나씩 연결하지말고 ans=1+n+$전체 교점의 개수
//전체 교점의 개수를 어떻게 셀까

//교차하지 않는 경우를 세자
//arr 순회 하면서 2개 모두 끝난 선들의 개수를 같는 세그트리 관리 하면서 세자

int n;
long long ans;

int arr[1000001];

int sum[500001];

vector<int> pos[500001];

long long tree[2][4000001];
long long cnt[2][1000001];

long long update(int type, int s, int e, int node, int idx, int val) {
	if (s > idx || e < idx) return tree[type][node];
	if (s == e) return tree[type][node] = cnt[type][idx] = val;
	int m = (s + e) / 2;
	return tree[type][node] = update(type, s, m, node * 2, idx, val) + update(type, m + 1, e, node * 2 + 1, idx, val);
}

long long get(int type, int s, int e, int node, int l, int r) {
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tree[type][node];
	int m = (s + e) / 2;
	return get(type, s, m, node * 2, l, r) + get(type, m + 1, e, node * 2 + 1, l, r);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> arr[i];
		pos[arr[i]].push_back(i);
	}

	long long t = 0;
	for (int i = 1; i <= 2 * n; i++) {
		sum[arr[i]]++;
		if (sum[arr[i]] == 2) {

			t += get(0, 1, 2 * n, 1, 1, pos[arr[i]][0]) + get(1, 1, 2 * n, 1, pos[arr[i]][0], pos[arr[i]][1]);
			update(0, 1, 2 * n, 1, pos[arr[i]][1], 1);
			update(1, 1, 2 * n, 1, pos[arr[i]][0], 1);
		}
	}
	ans = (n * (n - 1)) / 2 - t + 1 + n;
	cout << ans;

}
