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

ll gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); } 
ll lcm(ll a, ll b) { return (a*b)/gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

#define maxn 100000+10

long n;
ll ft[maxn], a[maxn];

void update(long i, ll val) {
	for (; i <= n; i += (i&(-i))) ft[i] += val;
}

ll getSum(long i) {
	ll sum = 0;
	for (; i > 0; i -= (i&(-i))) sum += ft[i];
	return sum;	
}

int main() {
	fio;
		
	long test_cases;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> n;
		memset(ft, 0, sizeof(ft));
		
		FOR(i, 1, n) {
			cin >> a[i];
			update(i, a[i]);	
		}

		long day = 0;
		long remain = n-1;
		long known = 1;
		
		while (remain > 0) {
			known += getSum(known);
			remain = n - known;
			
			day++;
		}
				
		cout << day << "\n";
	}
	
	return 0;
}
