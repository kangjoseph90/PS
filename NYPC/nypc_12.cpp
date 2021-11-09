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
	cin.tie();
	cout.tie();
};

void precision(int x) {
	cout << fixed;
	cout.precision(x);
}

int norm(int x) {
	return MAX(x, -1);
}

ll n,k;

ll arr[200001];

ll ans;

multiset<ll> s;

ll f() {
	ll sum = 0;
	auto iter1 = s.begin();
	auto iter2 = s.begin();
	iter2++;
	for (ll i = 1; i < k; i++) {
		sum += (k - i) * i * (*iter2 - *iter1);
		iter2++;
		iter1++;
	}
	return sum;
}

int main() {
	fastio();
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < k; i++) {
		s.insert(arr[i]);
	}
	for (int i = k; i < n; i++) {
		ans = MAX(ans, f());
		//cout << f()<<'\n';
		multiset<ll>::iterator iter = s.find(arr[i - k]);
		s.erase(iter);
		s.insert(arr[i]);
	}
	ans = MAX(ans, f());
	cout << ans;
}