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

#define mod  1000000007
#define maxk 10000 + 10

long q[maxk];

int main() {
	fio;

	long test_cases, n, k;
	ll res;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> n >> k;
		if (n < (k * (k + 1))/2) {
			cout << -1 << "\n";
			continue;
		}
		// FOR(i, 1, k) q.push(i);
		long remain = n - (k * (k+1))/2;
		ll res = 1;
		if (remain == 0) {
			FOR(i, 1, k) {
				res = (((res * i) % mod) * (i - 1)) % mod;
			}
			cout << res << "\n";
			continue;
		}

		memset(q, 0, sizeof(q));

		long x = remain / k;

		FOR(i, 1, k) q[i] = i + x;

		remain -= (x*k);

		long index = k;
		FOR(i, 1, remain) {
			q[index--]++;
		}

		FOR(i, 1, k) {
			res = (((res * q[i]) % mod) * (q[i] - 1)) % mod;
		}

		cout << res << "\n";
	}

	return 0;
}
