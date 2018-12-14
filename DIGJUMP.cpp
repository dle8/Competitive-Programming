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

#define oo 1000000000
#define maxn 100000 + 10

bool check[maxn];

int main() {
	fio;
	string s;

	cin >> s;
	long n = int(s.length());

	vector<vi> t(256);

	FOR(i, 0, n - 1) {
		t[s[i]].pb(i);
	}

	memset(check, false, sizeof(check));

	queue<pii> q;
	q.push(mp(0, 0));
	check[0] = true;
	long res = oo;

	while (!q.empty()) {
		pii u = q.front();
		q.pop();

		check[u.fi] = true;

		if (u.fi == n - 1) return cout << u.se, 0;

		if (u.fi + 1 < n && !check[u.fi + 1]) {
			q.push(mp(u.fi + 1, u.se + 1));
			check[u.fi + 1] = true;
		}

		if (u.fi - 1 >= 0 && !check[u.fi - 1]) {
			q.push(mp(u.fi - 1, u.se + 1));
			check[u.fi - 1] = true;
		}

		FOR(i, 0, int(t[s[u.fi]].size()) - 1) {
			if (!check[t[s[u.fi]][i]]) {
				q.push(mp(t[s[u.fi]][i], u.se + 1));
				check[t[s[u.fi]][i]] = true;
			}
		}

		t[s[u.fi]].clear();// cai tien
	}

	return 0;
}
