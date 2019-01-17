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
#define sz(x) int(x.size())
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

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll lcm(ll a, ll b) { return (a*b)/__gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

/* tach xau
string str = "Hello World"; stringstream ss(str);
while (ss >> token) cout << token << endl;
*/

const ll mod = 998244353;
#define maxn 300000 + 10
ll p[maxn], nodescc, col[maxn], parent[maxn], n, m, odd;
vector<vll> neighbor(maxn);
bool invalid;

void dfs(long u, long color) {
	nodescc++;
	col[u] = color;
	if (color == 1) odd++;
	FOR(i, 0, sz(neighbor[u]) - 1) {
		long v = neighbor[u][i];
		if (parent[v] == 0) {
			parent[v] = u;
			dfs(v, 3 - color);
		}
		else if (col[v] == color) {
			invalid = true;
			return;
		}
		if (invalid) return;
	}
}

int main() {
	fio;
	ll u, v, test;
	p[0] = 1;
	FOR(i, 1, maxn) p[i] = (p[i - 1] * 2) % mod;
	cin >> test;
	FOR(current_test, 1, test) {
		cin >> n >> m;
		FOR(i, 1, n) neighbor[i].clear(), parent[i] = 0;
		FOR(i, 1, m) {
			cin >> u >> v;
			neighbor[u].pb(v);
			neighbor[v].pb(u);
		}

		ll res = 1;
		invalid = false;
		FOR(i, 1, n) {
			if (parent[i] == 0) {
				parent[i] = -1;
				nodescc = 0;
				odd = 0;
				dfs(i, 1);
				if (invalid) break;
				ll tcount = (p[odd] + p[nodescc - odd]) % mod;
				res = (res * tcount) % mod;
			}
		}
		if (invalid) res = 0;
		cout << res << '\n';
	}

	return 0;
}
