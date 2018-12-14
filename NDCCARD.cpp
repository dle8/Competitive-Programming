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

ll max(ll a, ll b) { return ((a>=b)?a:b); }
ll min(ll a, ll b) { return ((a<=b)?a:b); }
ll gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); } 
ll lcm(ll a, ll b) { return (a*b)/gcd(a, b); }

#define maxn 10000+10

long a[maxn];

int main() {
	fio;
		
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);	
	
	long n, m, fp, sp, r, res, thisRound;	
	cin >> n >> m;
	FOR(i, 1, n) cin >> a[i];
	
	sort(a+1, a+1+n);
	
	res = 0;
	FOR(i, 1, n) {
		if (a[i] - (m/3) > eps) break;
		r = m - a[i];
		fp = 1;
		sp = n;
		thisRound = 0;
		while (true) {
			if (fp == i) fp++;
			if (sp == i) sp--;
			if (fp == n+1 || sp == 0 || fp == sp) break;//break when goes out of bound or when fp meets sp
			
			if (a[fp] + a[sp] <= r) {
				thisRound = max(thisRound, a[fp] + a[sp]);
				fp++;	
			}
			else sp--;
		}
		res = max(res, thisRound + a[i]);
	}
	
	cout << res;
	return 0;
}
