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

char board[100][100];

int h, w;

int k;

vector<pii> hole;

vector<pii> v; 

int ans = 0;

char ans_board[100][100];

char temp_board[100][100];

bool visited[100][100];

char mirror[5] = { '.','/','\\','|','-' };

int ans_hole;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 }; //down up right left

struct aa {
	int y, x, dir;
	bool error() {
		if (y == -1 && x == -1 && dir == -1) return true;
		if (y > 2 * h || y < 0 || x>2 * w || x < 0) return true;
		return false;
	}
};

aa next(aa now) {
	int y = now.y;
	int x = now.x;
	int dir = now.dir;
	char compare = temp_board[y][x];
	if (y < 0 || y>2 * h || x < 0 || x>2 * w) return { -1,-1,-1 };
	if (compare == '.')  return {y+dy[dir],x+dx[dir],dir};
	if (compare == '\\') {
		if (dir == 0) return { y + dy[2],x + dx[2],2 };
		if (dir == 1) return { y + dy[3],x + dx[3],3 };
		if (dir == 2) return { y + dy[0],x + dx[0],0 };
		if (dir == 3) return { y + dy[1],x + dx[1],1 };
	}
	else if (compare == '/') {
		if (dir == 0) return { y + dy[3],x + dx[3],3 };
		if (dir == 1) return { y + dy[2],x + dx[2],2 };
		if (dir == 2) return { y + dy[1],x + dx[1],1 };
		if (dir == 3) return { y + dy[0],x + dx[0],0 };
	}
	else if (compare == '|') {
		if (dir == 0 || dir == 1) return { -1,-1,-1 };
		if (dir == 2) return { y+dy[3],x+dx[3],3 };
		if (dir == 3) return { y+dy[2],x+dx[2],2 };
	}
	else if (compare == '-') {
		if (dir == 2 || dir == 3) return { -1,-1,-1 };
		if (dir == 0) return { y+dy[1],x+dx[1],1 };
		if (dir == 1) return { y+dy[0],x+dx[0],0 };
	}
	return { -1,-1,-1 };
}

void solve(int start, aa now,int len,bool check) {
	if (board[now.y][now.x] == 'H') {
		if (check) {
			if (now.y == hole[start].first && now.x == hole[start].second) len /= 2;
			if (ans < len) {
				for (int i = 0; i <= 2 * h; i++) {
					for (int j = 0; j <= 2 * w; j++) {
						ans_board[i][j] = temp_board[i][j];
					}
				}
				ans = len;
				ans_hole = start;
			}
			return;
		}
		check = true;
	}
	int ny = now.y + dy[now.dir];
	int nx = now.x + dx[now.dir];
	if (ny < 0 || ny > 2 * h || nx < 0 || nx > 2 * w) return;
	if (board[ny][nx] == '?'&&!visited[ny][nx]) {
		for (int i = 0; i < 5; i++) {
			temp_board[ny][nx] = mirror[i];
			aa temp = next({ ny ,nx,now.dir });
			if (temp.error()) continue;
			visited[ny][nx] = true;
			solve(start, temp, len + 2,check);
			visited[ny][nx] = false;
			temp_board[ny][nx] = '?';
		}
	}
	else if (board[ny][nx] == '@') return;
	else {
		aa temp = next({ ny,nx,now.dir });
		if (temp.error()) return;
		solve(start, temp, len + 2,check);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin >> h >> w;
	for (int i = 1; i < 2 * h; i += 2) {
		for (int j = 1; j < 2 * w; j += 2) {
			cin >> board[i][j];
			temp_board[i][j] = board[i][j];
			if (board[i][j] == '?') v.push_back({ i,j });
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		hole.push_back({ y,x });
		board[y][x] = 'H';
	}
	for (int i = 0; i < hole.size(); i++) {
		cout << i + 1 << '/' << hole.size() << '\n';
		int dir;
		if (hole[i].first == 0) dir = 0;
		if (hole[i].first == 2 * h) dir = 1;
		if (hole[i].second == 0) dir = 2;
		if (hole[i].second == 2 * w) dir = 3;
		solve(i, { hole[i].first,hole[i].second,dir }, 0, false);
	}
	cout << hole[ans_hole].second << ' ' << hole[ans_hole].first << '\n';
	for (int i = 1; i < 2 * h; i+=2) {
		for (int j = 1; j < 2 * w; j+=2) {
			if (ans_board[i][j] == '?') cout << '.';
			else cout << ans_board[i][j];
		}
		cout << endl;
	}
	cout << ans;
}