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

#define maxn 100000 + 10
long a[maxn], ans[maxn], increase[maxn], decrease[maxn];
bool check[maxn];

int main() {
	fio;

	long n;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];

	bool flag = false;
	REP(i, n, 2) {
		if (a[i] > a[i - 1]) increase[i - 1] = increase[i] + 1;
		if (a[i] < a[i - 1]) decrease[i - 1] = decrease[i] + 1;
		if (increase[i - 1] >= 5 || decrease[i - 1] >= 5) flag = true;
	}

	FOR(i, 1, n) {
		if (i > 4 && increase[i - 4] == 4 && decrease[i + 1] == 4 && a[i] == a[i + 1]) flag = true;
		if (i > 4 && decrease[i - 4] == 4 && increase[i + 1] == 4 && a[i] == a[i + 1]) flag = true;
	}

	if (flag) return cout << -1, 0;

	memset(check, false, sizeof(check));
	FOR(i, 1, n) {
		if (increase[i] >= 0) {
			if (a[i - 1] < a[i] && i > 1) {
				if (increase[i] == 0 && decrease[i] > 0) ans[i] = 5;
				else ans[i] = ans[i - 1] + 1;
			}
			else if (increase[i] > 0) ans[i] = 1;
		}
		if (decrease[i] >= 0) {
			if (a[i - 1] > a[i] && i > 1) {
				if (decrease[i] == 0 && increase[i] > 0) ans[i] = 1;
				else ans[i] = ans[i - 1] - 1;
			}
			else if (decrease[i] > 0) ans[i] = 5;
		}
	}

	FOR(i, 1, n) {
		if (ans[i] == 0) {
			FOR(j, 1, 5) if (j != ans[i - 1] && j != ans[i + 1]) {
				ans[i] = j;
				break;
			}
		}
	}

	FOR(i, 1, n) cout << ans[i] << " ";

	return 0;
}
