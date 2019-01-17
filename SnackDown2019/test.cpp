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

#define maxn 100000+10

long a[maxn], tcopy[maxn];

int main() {
	fio;
	FOR(i1, 2, 50 - 3)
	FOR(i2, i1 + 1, 50 - 2)
	FOR(i3, i2 + 1, 50 - 1) {
		bool flag = false;
		FOR(i4, 2, 50) {
			if (gcd(i4, i3) == 1 && gcd(i4, i2) == 1 && gcd(i4, i1) == 1) {
				flag = true;
			}
		}
		if (!flag) cout << i1 << " " << i2 << " " << i3 << "\n";	
	}	
	return 0;
}
