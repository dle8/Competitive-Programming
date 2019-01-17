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

const long mod = 1000000007;

struct node {
	long value, counter;
	bool left = false;
	bool right = false;
};

bool cmp(const node&x, const node&y) {
	return (x.value < y.value);
}

#define maxn 100000 + 10
node a[2 * maxn];
long l[maxn], r[maxn];

int main() {
	fio;

	long n, x, y;
	cin >> n >> x >> y;
	FOR(i, 1, n) {
		cin >> l[i] >> r[i];
		a[2 * i - 1].value = l[i];
		a[2 * i - 1].left = true;
		a[2 * i].value = r[i];
		a[2 * i].right = true;
		a[2 * i].counter = l[i];
	}

	sort(a + 1, a + 1 + 2 * n, &cmp);
	long tmp = 1;
	ll cost = 0;
	FOR(i, 1, (2 * n)) {
		if (a[i].left) {
			cost += ((y * (a[i].value - tmp) < x) ? y * (a[i].value - tmp) : x);
		}
		else {
			tmp = a[i].value;
			cost += y * (a[i].value - a[i].counter);
		}
	}

	cout << cost;

	return 0;
}
