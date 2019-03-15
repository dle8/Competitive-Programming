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

ll cnt[5];

int main() {
	fio;
	FOR(i, 1, 4) cin >> cnt[i];
	if (cnt[1] == cnt[4]) {
		if (cnt[1] == 0 && cnt[3] != 0) cout << 0;
		else cout << 1;
	}
	else cout << 0;
	return 0;
}
