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
long a[maxn][maxn], f[maxn][maxn];

int main() {
	fio;
		
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	long n, k;
	cin >> n >> k;
	FOR(i, 1, n)
	FOR(j, 1, n) cin >> a[i][j];
	
	//f[i][j] = tong cua hinh chu nhat co dinh trai tren la (1, 1) va dinh phai duoi la (i, j)
	
	FOR(i, 1, n)
	FOR(j, 1, n) {
		f[i][j] = a[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
	}
	
	long res = 0;
	FOR(i, 1, n)
	FOR(j, 1, n) {
		if (i - k < 0 || j - k < 0) continue;
		res = max(res, f[i][j] - f[i][j - k] - f[i - k][j] + f[i - k][j - k]);
	}
	
	cout << res;
	return 0;
}
