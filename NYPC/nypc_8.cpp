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


//작은거부터 터트리자

int n, k;

int arr[300001];

bool check[300001];

pair<int, int> sorted[300001]; //val,idx

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sorted[i] = { arr[i],i };
	}
	sort(sorted, sorted + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int now = sorted[i].first;
		int idx = sorted[i].second;
		if (check[idx]) continue;
		cnt++;
		for (int j = idx; j < n; j++) {
			if (arr[j] > now + k || arr[j] < now) break;
			else check[j] = true;
		}
		for (int j = idx; j >= 0; j--) {
			if (arr[j] > now + k || arr[j] < now) break;
			else check[j] = true;
		}
	}
	cout << cnt;
}