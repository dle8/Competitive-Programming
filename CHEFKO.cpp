/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, r, l) for (int i = r; i >= l; i--)
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

#define oo 1000000000 + 10
#define maxn 100000 + 10

pll segment[maxn];
long num[2 * maxn], ft[2 * maxn], n, rr;
unordered_map<long, long> roirac, rroirac;


bool cmp(const pll&x, const pll&y) {
	return (x.se < y.se || (x.se == y.se && x.fi > y.fi));
}

void update(long i) {
	for(; i <= rr; i += (i&(-i))) ft[i]++;
}

long sum(long i) {
	long sum = 0;
	for (; i > 0; i -= (i&(-i))) sum += ft[i];
	return sum;
}

long sum(long l, long r) {
	return sum(r) - sum(l - 1);
}

int main() {
  fio;

	long test_cases, index, tmp, k, last, res;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> n >> k;

		memset(ft, 0, sizeof(ft));

		index = 0;
		FOR(i, 1, n) {
				cin >> segment[i].fi >> segment[i].se;
				num[++index] = segment[i].fi;
				num[++index] = segment[i].se;
		}

		sort(num + 1, num + 1 + index);

		last = oo;
		rr = 0;
		roirac.clear();
		rroirac.clear();

		FOR(i, 1, index) {
			if (num[i] != last) {
				last = num[i];
				rr++;
			}
			roirac[num[i]] = rr;
			rroirac[rr] = num[i];
		}

		sort(segment + 1, segment + 1 + n, &cmp);

		res = 0;
		REP(i, n, 1) {
			update(roirac[segment[i].fi]);
			if (i > n - k + 1) continue;
			tmp = sum(1, roirac[segment[i].fi]);
			if (tmp >= k) {
				res = max(res, segment[i].se - segment[i].fi);
				continue;
			}
			//bs tim vi tri xa nhat thuoc doan thang dang xet hien tai ma dc bao boi it nhat k - 1 thang
			long d = roirac[segment[i].fi];
			long c = roirac[segment[i].se];

			while (d <= c) {
				long mid = (d + c) / 2;
				long tmp = sum(1, mid);
				if (tmp >= k) c = mid - 1;
				else d = mid + 1;
			}
			res = max(res, segment[i].se - rroirac[d]);
		}
		 cout << res << "\n";
	}

	return 0;
}
