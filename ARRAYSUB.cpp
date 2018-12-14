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

ll gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); } 
ll lcm(ll a, ll b) { return (a*b)/gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

#define maxn 100000+10
#define oo 1000000000

ll it[4*maxn], a[maxn];

void update(long cs, long u, long v) {
	if (u > v) return;
	if (u == v) {
		it[cs] = a[u];
		return;
	}
	long mid = (u + v)/ 2;
	update(2 * cs, u, mid);
	update(2 * cs + 1, mid + 1, v);
	it[cs] = max(it[2 * cs], it[2 * cs + 1]);
}

ll getMax(long cs, long u, long v, long l, long r) {
	if (r < u || v < l) return 0;
	if (l <= u && v <= r) return it[cs];
	long mid = (u+v)/2;
	return max(getMax(2*cs, u, mid, l, r), getMax(2*cs+1, mid+1, v, l, r));
}

int main() {
	fio;
		
	long n, k;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	cin >> k;
	
	update(1, 1, n);
	FOR(i, 1, n-k+1) {
		cout << getMax(1, 1, n, i, i+k-1) << " ";
	}	
	return 0;
}
