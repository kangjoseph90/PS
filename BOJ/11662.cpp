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
#include <cmath>


#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
#define all(x) x.begin(),x.end()

using namespace std;

struct vec2D {
	double x, y;

	vec2D operator+(vec2D operand) {
		return { x + operand.x,y + operand.y };
	}

	vec2D operator*(double operand) {
		return { x * operand,y * operand };
	}

	vec2D operator-(vec2D operand) {
		return { x - operand.x,y - operand.y };
	}

	double norm() {
		return sqrt(x * x + y * y);
	}

};

vec2D a, b, c, d;

double f(double t) {
	return ((a - c) * (1 - t) + (b - d) * t).norm();
}

int main() {
	double ax, ay, bx, by, cx, cy, dx, dy;
	cout << fixed;
	cout.precision(10);
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
	a = { ax,ay }; b = { bx,by }; c = { cx,cy }; d = { dx,dy };
	double s = 0, e = 1;
	while (e - s > 1e-8) {
		double p = (2 * s + e) / 3, q = (s + 2 * e) / 3;
		double fp = f(p), fq = f(q);
		if (fp >= fq) s = p;
		if (fq >= fp) e = q;
	}
	cout << f((s + e) / 2);
}
