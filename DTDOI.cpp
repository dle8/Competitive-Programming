/*
Author: Dung Tuan Le
University of Rochester
Created: 07/19/18
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
typedef vector<bool> vb;

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

const ll oo = 1e18;

#define maxn 100+10

ll n, s, price[maxn];

ll min(ll a, ll b) {
	return (a<=b)?a:b;
}

ll cal(long money, vll &num, vb &calculated) {
	if (money == 0) return 0;
	
	num[money] = oo;
	FOR(i, 1, n) {
		if (money < price[i]) continue;
		if (calculated[money - price[i]]) num[money] = min(num[money], num[money - price[i]]+1);
		else num[money] = min(num[money], cal(money-price[i], num, calculated)+1);
	}

	calculated[money] = true;
	return num[money];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);	
	
	cin >> n >> s;
	FOR(i, 1, n) cin >> price[i];
	vll num(s, 0);
	vb calculated(s, false);
	
	cout << cal(s, num, calculated);
	
	return 0;
}
