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

#define maxn 1000+10

vector<int> solution(int d, vector<int> &a) {
	int n = a.size();
	int tnext[maxn][12];
	memset(tnext, 0, sizeof(tnext));
	
	FOR(u, 1, n) {
		tnext[u][0] = a[u - 1] + 1;	
	}
	
	FOR(i, 1, int(log(n)/log(2))) 
	FOR(u, 1, n) {
		if (tnext[tnext[u][i-1]][i-1] != 0)
			tnext[u][i] = tnext[tnext[u][i-1]][i-1];
	}
	
	vector<int> power; power.clear();
	int tmp = d-1;
	REP(i, int(log(d)/log(2)), 0) {
		if (tmp - pow(2, i) >= 0) {
			power.pb(i);
			tmp -= pow(2, i);
		}
	}
	vector<int> res; res.clear();
	FOR(u, 1, n) {
		int ancestor = tnext[u][0];
		bool flag = true;
		for (auto iter = power.begin(); iter != power.end(); iter++) {
			if (tnext[ancestor][*iter] == 0) {
				res.pb(-1);
				flag = false;
				break;
			}
			ancestor = tnext[ancestor][*iter];
		}
		if (flag) res.pb(ancestor - 1);
	}
	
	return res;
}

int main() {
	fio;
	long n, v, d;
	vector<int> a;
	cin >> n >> d;
	FOR(i, 1, n) {
		cin >> v;
		a.pb(v);
	}
	
	vector<int> sol = solution(d, a);
	
	for (auto iter = sol.begin(); iter != sol.end(); iter++)
		cout << *iter << " ";
	return 0;
}
