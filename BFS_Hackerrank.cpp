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

#define maxn 1000 + 10

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
	bool visited[maxn];
	memset(visited, false, sizeof(visited));

	queue<pii> q;
	visited[s] = true;
	q.push(mp(s, 0));

	long d[maxn];
	FOR(i, 1, n) d[i] = -1;
	d[s] = 0;
	while (!q.empty()) {
		pii u = q.front();
		q.pop();

		FOR(i, 0, int(edges[u.fi].size()) - 1) {
			long v = edges[u.fi][i];
			if (!visited[v]){
				visited[v] = true;
				d[v] = 6 * (u.se + 1);
				q.push(mp(v, u.se + 1));
			}
		}
	}

	vi ans; ans.clear();
	FOR(i, 1, n)
		if (i != s) ans.pb(d[i]);

	return ans;
}

int main() {
	fio;

	long test_cases, n, m, u, v, s;

	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> n >> m;

		vector<vi> edges(maxn);
		FOR(i, 1, m) {
			cin >> u >> v;
			edges[u].pb(v);
			edges[v].pb(u);
		}

		cin >> s;
		vi ans = bfs(n, m, edges, s);

		for (auto iter = ans.begin(); iter != ans.end(); iter++)
			cout << *iter << " ";

		cout << "\n";
	}

	return 0;
}
