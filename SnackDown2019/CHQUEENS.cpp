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

long n, m, kingx, kingy;

bool satisfy(long x1, long y1, long x2, long y2) {
	if ((x1 == kingx && y1 == kingy) || (x2 == kingx && y2 == kingy) || (x1 == x2 && y1 == y2)) return false;
	if (x1 == x2) {
		if (x2 == kingx && abs(kingy - y1) + abs(y2 - kingy) == abs(y2 - y1)) return true;
		else return false;
	}
	if (y1 == y2) {
		if (y2 == kingy && abs(kingx - x1) + abs(x2 - kingx) == abs(x2 - x1)) return true;
		else return false;
	}
	if (abs(x2 - x1) == abs(y2 - y1)) {
		if (abs(kingx - x1) == abs(kingy - y1) && abs(kingy - y1) + abs(y2 - kingy) == abs(y2 - y1) && abs(kingx - x1) + abs(x2 - kingx) == abs(x2 - x1)) return true;
		else return false;
	}
	return ((abs(x2 - x1) != abs(y2 - y1)));
}

bool isKing(long x, long y) {
	return (x == kingx && y == kingy);
}

int main() {
	fio;

	long test_cases;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> n >> m >> kingx >> kingy;

		long res = 0;
		FOR(x1, 1, n)
		FOR(y1, 1, m) {
			long tmp = 0;
			if (isKing(x1, y1)) continue;
			tmp += (n * (m - y1 + 1));
			tmp -= 1;
			if (kingx >= x1) {
				tmp--;
			}
			FOR(y2, y1 + 1, m) {
				if (isKing(x1, y2)) {
					break;
				}
				tmp--;
			}

			if (kingx < x1) {
				tmp -= (n - kingx - 1);
			}
			else tmp -= (kingx - 1 - 1);

			FOR(i, 1, 100) {
				if (isKing(x1 + i, y1 + i) || x1 + i > n || y1 + i > m) break;
				tmp--;
			}

			FOR(i, 1, 100) {
				if (isKing(x1 - i, y1 + i) || x1 - i == 0 || y1 + i > m) break;
				tmp--;
			}

			if (tmp > 0)
				res += (2 * tmp);
			// if (x1 == 1 && y1 == 1) cout << tmp << "\n";
 		}

		cout << res << "\n";
	}

	return 0;
}
