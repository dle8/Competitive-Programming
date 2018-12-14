/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define eps 1e-9

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<ll, ll> pllll;
/*typedef pair<ld, ld> Point;
typedef pair<Point, Point> line;
struct strLine { ld a, b, c; };*/

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

struct Point {
	ld x, y;
	long sh;
};

bool cw (Point a, Point b, Point c) { return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0; }
bool ccw (Point a, Point b, Point c) { return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0; }
bool linear (Point a, Point b, Point c) { return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) == 0; }

#define maxn 10000+10
#define oo 1000000000

bool inCH[maxn];
vector<Point> points, up, down, cpoints, convexHull;

bool cmp(const Point &p1, const Point &p2) {
	return (p1.x < p2.x || p1.x == p2.x && p1.y < p2.y);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long test_cases, n;
	ld x, y;
	Point tmp;
	
	while (true) {
		cin >> n;
		if (n==0) break;
		points.clear();
		cpoints.clear();
		FOR(i, 0, n-1) {
			cin >> tmp.x >> tmp.y;
			tmp.sh = i;
			
			cpoints.pb(tmp);
		}

		sort(cpoints.begin(), cpoints.end(), &cmp);
		tmp.x = oo; tmp.y = oo;
		cpoints.pb(tmp);
		
		FOR(i, 0, cpoints.size()-2) {
			if (cpoints[i].x == cpoints[i+1].x && cpoints[i].y == cpoints[i+1].y) continue;
			points.pb(cpoints[i]);
		}
		
		up.clear(); down.clear();
		Point p1 = points.front(); Point p2 = points.back();
		
		up.pb(p1); down.pb(p1);
		
		for (size_t i=1; i<points.size(); i++) {
			if (i == points.size()-1 || cw(p1, points[i], p2)) {
				while (up.size()>=2 && !cw(up[up.size()-2], up[up.size()-1], points[i])) up.pop_back();
				up.pb(points[i]);
			}
			
			if (i == points.size()-1 || ccw(p1, points[i], p2)) {
				while (down.size()>=2 && !ccw(down[down.size()-2], down[down.size()-1], points[i])) down.pop_back();
				down.pb(points[i]);
			}
		}
		
		convexHull.clear();
		for (size_t i=0; i<up.size(); i++)
			convexHull.pb(up[i]);
		
		for (size_t i=1; i<down.size()-1; i++)
			convexHull.pb(down[i]);		

		cout << convexHull.size() << "\n";
		REP(i, convexHull.size()-1, 0)
			cout << convexHull[i].x << " " << convexHull[i].y << "\n";
	}
	
	return 0;
}
