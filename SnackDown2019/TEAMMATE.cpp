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
#define maxs 1000000+10

const long mod = 1e9+7;

long tcount[maxs], s[maxn];
set<long> Set;
unordered_multiset<long> mSet;

int main() {
	fio;
	
	long test_cases, index, n, numth, tmp;	
	ll res;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		Set.clear(); 
		mSet.clear();
		cin >> n;
		FOR(i, 1, n) {
			cin >> s[i];
			Set.insert(s[i]);
			mSet.insert(s[i]);
		}
		
		res = 1;
		numth = 0;
		for (auto iter = Set.begin(); iter != Set.end(); iter++) {
			if (numth <= 1) res = (res * mSet.count(*iter)) % mod;
			else {
				if (tmp > 1) res = (res * (tmp - 1)) % mod;
				res = (res * mSet.count(*iter)) % mod;
			}	
			numth++;
			tmp = mSet.count(*iter);
		}
		
		cout << res << "\n";
	}
	
	return 0;
}
