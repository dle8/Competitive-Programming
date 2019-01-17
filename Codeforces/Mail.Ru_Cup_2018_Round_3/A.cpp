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

#define maxn 100 + 10

int main() {
	fio;

	long n, r, tram[maxn];
	cin >> n;

	multiset<long> mset[maxn];

	FOR(i, 1, n) {
		cin >> r;
		FOR(j, 1, r) {
			cin >> tram[j];
			mset[i].insert(tram[j]);
		}
	}

	for (auto iter = mset[1].begin(); iter != mset[1].end(); iter++) {
		long times = mset[1].count(*iter);
		FOR(i, 2, n) {
			times = min(times, mset[i].count(*iter));
		}
		FOR(i, 1, times) cout << *iter << " ";
	}

	return 0;
}
