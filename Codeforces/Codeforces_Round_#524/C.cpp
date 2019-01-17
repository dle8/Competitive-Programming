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

ll color(ll x, ll y) {
	if (x % 2 == 0) return ((y % 2 == 0) ? 0 : 1);
	return ((y % 2 == 0) ? 1 : 0);
}

ll lostBlack(ll lleftx, ll llefty, ll trightx, ll trighty) {
	ll start = color(lleftx, llefty);
	ll area = (trightx - lleftx + 1) * (trighty - llefty + 1);
	ll subBlack = area / 2;
	if (start == 1 && area % 2 != 0) subBlack++;
	return subBlack;
}

bool findIntersection(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4, pllll &lleft, pllll &tright) {
		lleft.fi = max(x1, x3);
    lleft.se = max(y1, y3);
    tright.fi = min(x2, x4);
    tright.se = min(y2, y4);
    if (lleft.fi > tright.fi || lleft.se > tright.se) return false;
		return true;
}

int main() {
	fio;

	ll test_cases, n, m, x[5], y[5], white = 0, black = 0;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> n >> m;
		FOR(i, 1, 4) cin >> x[i] >> y[i];

		black = (n * m) / 2;
		if ((n * m) % 2 != 0) white++;

		ll subBlack = lostBlack(x[1], y[1], x[2], y[2]);
		black -= subBlack;

		pllll lleft, tright;
		bool commonArea = findIntersection(x[1], y[1], x[2], y[2], x[3], y[3], x[4], y[4], lleft, tright);

		ll area, commonBlack;
		if (commonArea) {
			area = (tright.fi - lleft.fi + 1) * (tright.se - lleft.se + 1);
			commonBlack = area / 2;
			if (area % 2 != 0 && color(lleft.fi, lleft.se) == 1) commonBlack ++;
			black += commonBlack;
		}

		area = ((x[4] - x[3] + 1) * (y[4] - y[3] + 1));

		black += (area / 2);

		if (area % 2 != 0 && color(x[3], y[3]) == 0) black++;

		cout << (n * m) - black << " " << black << '\n';
	}

	return 0;
}
