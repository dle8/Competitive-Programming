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

#define maxn 100000 + 10
bool inQueue[maxn][5000];

int main() {
	fio;

	long n, m;
	cin >> n >> m;

	if (n == m) return cout << 0, 0;
	if (n > m) return cout << n - m, 0;

	queue<pii> q;
	q.push(mp(n, 0));

	memset(inQueue, false, sizeof(inQueue));
	inQueue[n][0] = true;

	while (!q.empty()) {
		pii u = q.front();
		q.pop();

		inQueue[u.fi][u.se] = false;
		if (u.fi == m) return cout << u.se, 0;

		if (!inQueue[u.fi * 2][u.se + 1] && u.fi < m) {
				inQueue[u.fi * 2][u.se + 1] = true;
				q.push(mp(u.fi * 2, u.se + 1));
		}
		if (!inQueue[u.fi - 1][u.se + 1] && u.fi - 1 >= 0) {
				inQueue[u.fi - 1][u.se + 1] = true;
				q.push(mp(u.fi - 1, u.se + 1));
		}
	}

	return 0;
}
