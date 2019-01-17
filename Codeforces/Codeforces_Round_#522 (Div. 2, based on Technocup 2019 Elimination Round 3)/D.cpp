/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define lb lower_bound
#define ub upper_bound
#define eps 1e-9

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<ll, ll> pllll;
typedef pair<ld, ld> Point;
typedef pair<Point, Point> line;
struct strLine { ld a, b, c; };

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

const double pi = 3.141592653589793;

ll gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
ll lcm(ll a, ll b) { return (a*b)/gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

Point u, v;
bool parallel, coincident;
// Distance between 2 points
ld distanceBetween(Point p1, Point p2) {
	return (sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)) * 100000) / 100000.0;
}

Point intersection(strLine l1, strLine l2) {
	ld d = l1.a * l2.b - l2.a * l1.b;
	ld dx = -(l1.c * l2.b - l2.c * l1.b);
	ld dy = l2.a * l1.c - l1.a * l2.c;

	if (d == 0) {
		if (dx != 0) parallel = true;
		else coincident = true;
	}

	if (d == 0) return mp(0, 0);
	return mp(dx / d, dy / d);
}

strLine newLine(ld a, ld b, ld c) {
	strLine line; line.a = a; line.b = b; line.c = c;
	return line;
}

bool outside(Point p1, Point u, Point v) {
	if (u.y < v.y && (p1.x - u.x < -eps || p1.x - v.x > eps || p1.y - u.y < -eps || p1.y - v.y > eps)) return true;
	if (u.y > v.y && (p1.x - u.x < -eps || p1.x - v.x > eps || p1.y - u.y > eps || p1.y - v.y < -eps)) return true;
	return false;
}

int main() {
	fio;

	Point u, v;
	ld a, b, c;

	cin >> a >> b >> c;
	strLine avenue = newLine(a, b, c);
	cin >> u.x >> u.y >> v.x >> v.y;
	if (u.x > v.x) swap(u, v);

	if (u.x == v.x) return cout << setprecision(9) << fixed << abs(u.y - v.y), 0;
	if (u.y == v.y) return cout << setprecision(9) << fixed << abs(u.x - v.x), 0;

	if ((a * u.x + b * u.y + c == 0) && (a * v.x + b * v.y + c == 0)) return cout << setprecision(9) << fixed << distanceBetween(u, v), 0;
	parallel = false;
	coincident = false;
	strLine up = newLine(0, 1, (u.y > v.y) ? -u.y : -v.y);
	strLine down = newLine(0, 1, (u.y > v.y) ? -v.y : -u.y);
	strLine left = newLine(1, 0, -u.x);
	strLine right = newLine(1, 0, -v.x);

	if (parallel || coincident) return cout << setprecision(9) << fixed << abs(u.x - v.x) + abs(u.y - v.y), 0;

	Point upPoint = intersection(avenue, up);
	Point downPoint = intersection(avenue, down);
	Point leftPoint = intersection(avenue, left);
	Point rightPoint = intersection(avenue, right);

	bool isLeft = false; bool isRight = false; bool isUp = false; bool isDown = false;
	Point tmp[10]; long index = 0;

	if (!outside(leftPoint, u, v)) {
		isLeft = true;
		tmp[++index] = leftPoint;
	}
	if (!outside(rightPoint, u, v)) {
		isRight = true;
		tmp[++index] = rightPoint;
	}
	if (!outside(upPoint, u, v)) {
		isUp = true;
		tmp[++index] = upPoint;
	}
	if (!outside(downPoint, u, v)) {
		isDown = true;
		tmp[++index] = downPoint;
	}

	if (!isLeft && !isRight && !isUp && !isDown) return cout << setprecision(9) << fixed << abs(u.x - v.x) + abs(u.y - v.y), 0;

	ld slope = -a / b;
	if ((u.y > v.y && slope > 0) || (u.y < v.y && slope < 0)) return cout << setprecision(9) << fixed << abs(u.x - v.x) + abs(u.y - v.y), 0;

	ld res = distanceBetween(tmp[1], tmp[2]) + ((isLeft) ? distanceBetween(leftPoint, u) : ld(0)) + ((isRight) ? distanceBetween(rightPoint, v) : ld(0))
	+ ((isUp && u.y > v.y) ? distanceBetween(upPoint, u) : ld(0)) + ((isUp && u.y < v.y) ? distanceBetween(upPoint, v) : ld(0)) + ((isDown && u.y < v.y) ? distanceBetween(downPoint, u) : ld(0))
	+ ((isDown && v.y < u.y) ? distanceBetween(downPoint, v) : ld(0));
	cout << setprecision(9) << fixed << res;

	return 0;
}
