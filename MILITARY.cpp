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
//typedef pair<ld, ld> Point;

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

#define maxn 4000+10

struct Point {
	long x, y, sh;
};

Point point[maxn];
long res;
bool out[maxn];

bool cmp(const Point&p1, const Point&p2) {
	return (p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y));
}

bool cw (Point a, Point b, Point c) { // a -> b -> c di theo th? t? xuôi chi?u kim d?ng h?
  	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) <= 0;
}

bool ccw (Point a, Point b, Point c) { // a -> b -> c di theo th? t? ngu?c chi?u kim d?ng h?
  	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) >= 0;
}

bool linear(Point a, Point b, Point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) == 0;
}

void convexHull(vector<Point> &a) {
	if (a.size() == 1) {
		return;
	}
	
	sort(a.begin(), a.end(), &cmp);
	
	Point p1 = a[0]; Point p2 = a.back();
	
	vector<Point> up, down;
	up.pb(p1);
	down.pb(p1);
	
	long inBound = 0;
	for (size_t i=1; i<a.size(); ++i) {
		if (i == a.size()-1 || cw(p1, a[i], p2)) {//tinh ca nhung diem thang hang
			while (up.size()>=2 && !cw(up[up.size()-2], up[up.size()-1], a[i])) up.pop_back();
			if (linear(up[up.size()-2], up[up.size()-1], a[i])) inBound++;
			up.pb(a[i]);
		}
		
		if (i == a.size()-1 || ccw(p1, a[i], p2)) {
			while (down.size()>=2 && !ccw(down[down.size()-2], down[down.size()-1], a[i])) down.pop_back();
			if (linear(down[down.size()-2], down[down.size()-1], a[i])) inBound++;
			down.pb(a[i]);
		}
	}
	a.clear();
	for (size_t i = 0; i<up.size(); i++)
		a.pb(up[i]);
	
	for (size_t i = down.size()-2; i>0; --i)
		a.pb(down[i]);
	
	for (size_t i=0; i<a.size(); i++) out[a[i].sh] = true;
	res++;
	//for (size_t i = 0; i<a.size(); i++) cout << a[i].x << " " << a[i].y << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long n;
	FOR(current_test, 1, 39) {
		
		string file = to_string(current_test);
		if (current_test<10) file = "0" + file;
		
		freopen(("MILITARY.I" + file).c_str(), "r", stdin);
		cin >> n;
		FOR(i, 1, n) {
			cin >> point[i].x >> point[i].y;
			point[i].sh = i;	
		}
		
		memset(out, false, sizeof(out));
		vector<Point> ch;
		res = 0;
		while (true) {
			ch.clear();
			FOR(i, 1, n) 
			if (!out[point[i].sh]) ch.pb(point[i]);
			if (ch.size() == 0) break;
			convexHull(ch);
		}	
		
		freopen(("MILITARY.A" + file).c_str(), "r", stdout);
		long ans;
		cin >> ans;
		if (res != ans) cout << "Test " << current_test << " is wrong: " << ans << " " << res << "\n";
		else cout << "Test " << current_test << "is correct\n";
	}
	return 0;
}
