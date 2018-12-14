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

#define maxn 20000 + 10
pii f[maxn];

bool cmp(const pii&x, const pii&y) {
	return (x.fi < y.fi || (x.fi == y.fi && x.se < y.se));
}

int findFirstEqual(int l, int r, int key) {
	int d = l;
	int c = r;

	while (d <= c) {
		int mid = (d + c) / 2;
		if (f[mid].fi >= key) c = mid - 1;
		else d = mid + 1;
	}

	return d;
}

int findLastEqual(int l, int r, int key) {
	int d = l;
	int c = r;

	while (d <= c) {
		int mid = (d + c) / 2;
		if (f[mid].fi <= key) d = mid + 1;
		else c = mid - 1;
	}

	return c;
}

int findLastSmaller(int l, int r, int key) {
	int d = l;
	int c = r;

	while (d <= c) {
		int mid = (d + c) / 2;
		if (f[mid].se < key) d = mid + 1;
		else c = mid - 1;
	}

	return c;
}

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
			f[0].fi = 0;
			f[0].se = 0;
			FOR(i, 1, n) {
				f[i].fi = f[i - 1].fi + nums[i - 1];
				f[i].se = i;
			}

			sort(fi, fi + 1 + n, &cmp); // sort includes 0

			int res = 0;
			FOR(i, 1, n) {
				int l = findFirstEqual(0, n, f[i].fi - k);
				int r = findLastEqual(0, n, f[i].fi - k);

				if (l > r || (f[i].l != f[i].fi - k)) continue;
				int lastSmaller = findLastSmaller(l, r, f[i].se);

				if (lastSmaller >= l)
					res += (lastSmaller - l + 1);
			}

			return res;
    }
};

int main() {
	fio;

	long n, k, x;
	cin >> n >> k;
	vi nums; nums.clear();
	FOR(i, 1, n) {
		cin >> x;
		nums.pb(x);
	}

	Solution sol;
	cout << sol.subarraySum(nums, k);

	return 0;
}
