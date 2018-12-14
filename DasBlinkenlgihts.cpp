/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<ll, ll> pllll;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll p, q, s;
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);	

	cin >> p >> q >> s;
	ll temp = p*q;
	temp /= gcd(p, q);
	if (temp<=s) return cout << "YES", 0;
	else return cout << "NO", 0;
	
	return 0;
}
