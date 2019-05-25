/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define FORALL(iter, x) for (auto iter = x.begin(); iter != x.end(); iter++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define eps 1e-9
#define sz(x) int(x.size())

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

/* tach xau
string str = "Hello World", token; stringstream ss(str);
while (ss >> token) cout << token << endl;
*/

/*
#ifdef _TIME
  //freopen("", "r", stdin);
  long tt = clock();
#endif

#ifdef _TIME
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
*/

#define maxn 1000 + 10
#define maxk 5 + 10
long n, k, a[maxk][maxn], deg[maxn], dp[maxn], cdeg[maxn];
bool edge[maxn][maxn], check[maxn];
vector<long> adj[maxn];

struct cmp {
	bool operator()(const long&x, const long&y) {
		return deg[x] > deg[y];
	}
};

int main() {
	fio;
	cin >> n >> k;
	FOR(i, 1, k) FOR(j, 1, n) cin >> a[i][j];
	memset(edge, false, sizeof(edge));
	FOR(i, 1, k) {
		FOR(j, 1, n - 1) FOR(u, j + 1, n) edge[a[i][j]][a[i][u]] = true;
	}
	FOR(i, 1, k) {
		FOR(j, 1, n - 1) FOR(u, j + 1, n) {
			edge[a[i][u]][a[i][j]] = false;
		}
	}
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			if (i != j && edge[i][j]) {
				// adj[i].pb(j);
				adj[j].pb(i);
				deg[j]++;
				cdeg[j]++;
			}
		}
	}
	priority_queue<long, vector<long>, cmp> pq;
	FOR(i, 1, n) pq.push(i);
	vector<long> v;
	memset(check, false, sizeof(check));
	while (!pq.empty()) {
		while (!pq.empty() && check[pq.top()]) pq.pop();
		if (pq.empty()) break;
		long u = pq.top();
		check[u] = true;
		pq.pop();
		v.pb(u);
		FOR(i, 0, sz(adj[u]) - 1) {
			deg[adj[u][i]]--;
			pq.push(adj[u][i]);
		}
	}
	memset(dp, 0, sizeof(dp));
	FOR(i, 0, sz(v) - 1) {
		if (cdeg[v[i]] == 0) dp[v[i]] = 1;
		// cout << v[i] << " " << cdeg[v[i]] << " " << dp[v[i]] << '\n';
		FOR(j, 0, sz(adj[v[i]]) - 1) dp[v[i]] = max(dp[v[i]], dp[adj[v[i]][j]] + 1);
	}
	long res = 0;
	FOR(i, 1, n) res = max(res, dp[i]);
	cout << res;
	return 0;
}
