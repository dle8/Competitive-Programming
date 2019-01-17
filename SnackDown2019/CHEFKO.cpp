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

struct pts {
	long val;
	bool left = false;
	bool right = false;
};

#define maxn 100000 + 10

pts point[2*maxn];
pll res[maxn];
long n, k;

bool cmp(const pts&a, const pts&b) {
	return ((a.val<b.val) || (a.val==b.val && a.left && b.right));
}

int main() {
  fio;
	long l, r, test_cases;
  cin >> test_cases;
  FOR(current_test, 1, test_cases) {
    cin >> n >> k;
    FOR(i, 1, n) {
  		cin >> l >> r;
  		point[2*i-1].val = l;
  		point[2*i-1].left = true;

  		point[2*i].val = r;
  		point[2*i].right = true;
  	}

  	sort(point+1, point+1+2*n, cmp);

  	long count = 0, seg = 0;
  	FOR(i, 1, 2*n) {
  		if (point[i].left) count++;
  		if (count==k) {
  			if (point[i].left) res[++seg].fi = point[i].val;
  			else res[seg].se = point[i].val;
  		}
  		if (point[i].right) count--;
  	}

    // ll longestSeg = 0;
    // FOR(i, 1, seg) longestSeg = max(longestSeg, res[i].se - res[i].fi);

    // cout << longestSeg << "\n";
    FOR(i, 1, seg) cout << res[i].fi << " " << res[i].se << "\n";
  }
	return 0;
}
