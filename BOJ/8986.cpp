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

#define ll long long

ll n;

ll arr[100001];



ll norm(ll x) {
	return MAX(x, -x);
}

ll f(ll x) {
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		sum += norm(arr[i] - x * i);
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> arr[i];
	ll s = 0;
	ll e = arr[n - 1];
	while (s + 2 < e) {
		ll p = (2 * s + e) / 3;
		ll q = (s + 2 * e) / 3;
		ll fp = f(p); ll fq = f(q);
		if (fp <= fq) {
			e = q;
		}
		if (fp >= fq) {
			s = p;
		}
	}
	ll ans = LLONG_MAX;
	for (ll i = s; i <= e; i++) {
		ll temp = f(i);
		ans = MIN(ans, temp);
	}
	cout << ans;
	
}