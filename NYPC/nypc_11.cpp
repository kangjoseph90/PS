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

//단순한 시뮬레이션일까?


int n, m;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

char dir[4] = { 'D','U','R','L' };

char board[25][25];

bool done = false;

bool visited[25][25][100000];


struct aa {
	int x, y, time;
	string cmd;
};

void solve() {
	queue<aa> q;
	q.push({ 0,0,0,""});
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int time = q.front().time;
		string temp = q.front().cmd;
		q.pop();
		if (x == m - 1 && y == n - 1) {
			cout << temp;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx == m || ny < 0 || ny == n) continue;
			if (board[ny][nx] == '#' || (board[ny][nx] >= '0' && board[ny][nx] <= '9')) continue;
			if (visited[ny][nx][time + 1]) continue;
			bool cango = true;
			for (int j = 0; j < 4; j++) {
				int nnx = nx + dx[j];
				int nny = ny + dy[j];
				if (nnx < 0 || nnx == m || nny < 0 || nny == n) continue;
				if (board[nny][nnx] >= '0' && board[nny][nnx] <= '9') {
					int num = board[nny][nnx] - '0';
					if (time % num != num - 1) cango = false;
				}
			}
			if (!cango) continue;
			q.push({ nx,ny,time + 1,temp+dir[i] });
			visited[ny][nx][time + 1] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	solve();
}