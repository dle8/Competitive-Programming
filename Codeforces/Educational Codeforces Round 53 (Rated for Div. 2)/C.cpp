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

#define maxn 200000 + 10
long n;

void move(char direction, long &x, long &y) {
	if (direction == 'L') x--;
	if (direction == 'R') x++;
	if (direction == 'U') y++;
	if (direction == 'D') y--;
}

int main() {
	fio;

	long x, y;
	string s;

	cin >> n;
	cin >> s;

	cin >> x >> y;

	if (abs(x) + abs(y) > n) return cout << -1, 0;
	if ((abs(x) + abs(y) - n) % 2 != 0) return cout << -1, 0;

	pll current = {0, 0};

	FOR(i, 0, n - 1) {
		move(s[i], current.fi, current.se);
	}

	long d = 0;
	long c = n;

	// binary search based on the length of minimum modified length
	bool exist = false;

	while (d <= c) {
		long mid = (d + c) / 2;

		pll place = {0, 0};

		bool find = false;

		FOR(i, mid, n - 1) {
			move(s[i], place.fi, place.se);
		}

		FOR(i, 0, n - mid) {
			if (i != 0) {
				move(s[i - 1], place.fi, place.se);
				if (s[i + mid - 1] == 'L') place.fi++;
				if (s[i + mid - 1] == 'R') place.fi--;
				if (s[i + mid - 1] == 'U') place.se--;
				if (s[i + mid - 1] == 'D') place.se++;
			}

			if (abs(x - place.fi) + abs(y - place.se) <= mid) {
				exist = true;
				find = true;
				break;
			}
		}

		if (find) c = mid - 1;
		else d = mid + 1;
	}

	cout << ((exist) ? d : -1);

	return 0;
}
