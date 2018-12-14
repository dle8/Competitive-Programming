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

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); } 
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll max(ll a, ll b) { return (a >= b) ? a : b; }
ll min(ll a, ll b) { return (a <= b) ? a : b; }

#define maxn 50+10
pll edge[50 * maxn];
long lab[maxn], child[maxn], a[maxn], head[maxn];
bool check[maxn];

long getRoot(long u) {
	if (lab[u] < 0) return u;
	return getRoot(lab[u]);
}

void dsu(long r1, long r2) {
	if (lab[r1] == lab[r2]) {
		lab[r1]--;
		lab[r2] = r1;
		return;
	}
	if (lab[r1] < lab[r2]) lab[r2] = r1;
	else lab[r1] = r2;
}

bool isPrime(long u) {
	if (u <= 1) return false;
	if (u == 2 || u == 3) return true;
	FOR(i, 2, sqrt(u))
		if (u % i == 0) return false;
	
	return true; 
}

int main() {
	fio;
		
	long test_cases, n, r1, r2, index;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> n;
		FOR(i, 1, n) {
			cin >> a[i];
			lab[i] = -1;
		}
		
		long index = 0;
		FOR(i, 1, n - 1)
		FOR(j, i + 1, n) {
			if (i != j && gcd(a[i], a[j]) == 1) {
				edge[++index].fi = i;
				edge[index].se = j;
			}
		}
		
		FOR(i, 1, index) {
			r1 = getRoot(edge[i].fi);
			r2 = getRoot(edge[i].se);
			if (r1 != r2) dsu(r1, r2);
		}
		
		long scc = 0;
		memset(check, true, sizeof(check));
		FOR(i, 1, n) {
			r1 = getRoot(i);
			if (check[r1]) {
				head[++scc] = r1;
				check[r1] = false;
			}
		}
		
		if (scc == 1) cout << 0 << "\n";
		else {
			cout << 1 << "\n";
			long tmp = 0;
			FOR(i, 2, scc)
				if (isPrime(a[head[i]])) tmp = head[i];
			
			if (tmp == 0) {
				a[head[1]] = 47;
			}
			else {//if a[tmp] ngto
				REP(k, 50, 2)
				if (isPrime(k) && gcd(k, a[tmp]) == 1) {
					a[head[1]] = k;
					break;
				}
			}
		}
	
		FOR(i, 1, n) cout << a[i] << " ";
		if (current_test != test_cases) cout << "\n";
	}
	
	return 0;
}
