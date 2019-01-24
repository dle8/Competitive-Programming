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
#define oo 1000000000

pii a[maxn];
bool exist[maxn];

bool cmp(const pii&x, const pii&y) {
	return (x.fi < y.fi);
}

int main() {
	fio;

	long test_cases, n;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> n;
		memset(exist, false, sizeof(exist));
		FOR(i, 1, n) {
			cin >> a[i].fi;
			a[i].se = i;
			exist[a[i].fi] = true;
		}

		sort(a + 1, a + 1 + n, &cmp);

		long last = oo;
		long count = 0;
		bool happy = false;
		FOR(i, 1, n) {
			if (a[i].fi != last) {
				last = a[i].fi;
				count = 0;
			}
			if (exist[a[i].se]) count++;
			if (count ==2) happy = true;
		}

		cout << ((happy) ? "Truly Happy" : "Poor Chef") << "\n";
	}

	return 0;
}
