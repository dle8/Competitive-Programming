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

#define maxn 300+10

pll house[300 * maxn];
long tcount[2 * maxn];

inline long mdist(pll h1, pll h2) {
	return abs(h1.fi - h2.fi) + abs(h1.se - h2.se);
}

int main() {
	fio;
		
	long test_cases, n, m;
	char c;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> n >> m;
		long index = 0;
		FOR(i, 1, n)
		FOR(j, 1, m) {
			cin >> c;
			if (c == '1') {
				house[++index].fi = i;
				house[index].se = j;
			}
		}
		
		memset(tcount, 0, sizeof(tcount));
		FOR(i, 1, index - 1)
		FOR(j, i+1, index) {
			tcount[mdist(house[i], house[j])]++;
		}
		
		FOR(i, 1, m + n - 2)
			cout << tcount[i] << " ";
		
		cout << "\n";
	}
	return 0;
}
