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

int main() {
	fio;

	string s;
	cin >> s;
	long n = int(s.length());
	cout << n << '\n';
	if (n <= 20) {
		cout << 1 << " " << n << '\n';
		return cout << s, 0;
	}

	long r = n / 20;
	long c = 20;
	long tmp = n - n % 20;
	while (tmp <= r) {
		tmp -= r;
		c--;
	}

	cout << n / 20 << " " << c << '\n';

	if (tmp <= 1) {
		FOR(i, 1, tmp) s += '*';
		FOR(i, 1, r) {
			FOR(j, 1, c) cout << s[(i - 1) * c + j - 1];
			cout << '\n';
		}
	}
	else {
		FOR(i, 1, r) {
			FOR(j, 1, c - 1) cout << s[(i - 1) * c + j - 1];
			if (tmp > 0) {
				cout << '*';
				tmp--;
			}
			cout << '\n';
		}
	}

	return 0;
}
