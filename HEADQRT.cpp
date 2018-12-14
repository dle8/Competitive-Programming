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
typedef pair<ld, ld> Point;
typedef pair<Point, Point> line;
struct strLine { ld a, b, c; };

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

vector<Point> ggl, micros;

bool cmp(const Point&p1, const Point &p2) {
	return (p1.x < p2.x || p1.x == p2.x  && p1.y < p2.y);
}

ld distanceBetween(Point p1, Point p2) {
	return (sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);	
	ld x, y;
	long of, test_cases, n;
	
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> n;
		
		ggl.clear();
		micros.clear();
		FOR(i, 1, n) {
			cin >> x >> y >> of;
			if (of == 0) micros.pb(mp(x, y));
			else ggl.pb(mp(x, y));
		}
		sort(micros.begin(), micros.end(), &cmp);
		sort(ggl.begin(), ggl.end(), &cmp);
		long tmp1 = long(distanceBetween(micros.front(), ggl.back()));
		long tmp2 = long(distanceBetween(micros.back(), ggl.front()));
		cout << ((tmp1>tmp2)?tmp1:tmp2) << "\n";
	}
	
	return 0;
}
