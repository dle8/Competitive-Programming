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
ll a[maxn], b[maxn];

int main() {
	fio;
	
	long n, test_cases;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> n;
		FOR(i, 1, n) cin >> a[i];
		FOR(i, 1, n) cin >> b[i];
		
		bool can = true;
		REP(i, n, 1) {
			if (a[i] == b[i]) continue;
			if (a[i] > b[i] || (b[i] - a[i]) % 3 != 0 || i < 2) can = false;
			if (!can) break;			
			a[i - 1] += (((b[i] - a[i])/3)*2);
			a[i - 2] += ((b[i] - a[i])/3);
		}
		
		cout << ((can) ? "TAK" : "NIE") << "\n";
	}
	
	return 0;
}
