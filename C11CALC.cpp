#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mod 1000000007
using namespace std;

typedef long long ll;
map<long, long> mymap;
long mang[100], n, k;

ll a(long x, long y) {
	ll res = 1;
	FOR(i, x+1, y) res = (res*i)%mod;
	return res;
}

ll c(long x, long y) {
	long index = 0;
	FOR(i, 1, x) mymap[i] = 1;
	FOR(i, y-x+1, y) {
		index++;
		mang[index] = i;
	}
	
	FOR(i, 1, index) 
	FOR(j, 1, x) {
		if (mymap[j]!=0 && mang[i]%j==0) {
			mymap[j] = 0;
			mang[i]/=j;
		}
	}
	
	ll res = 1;
	FOR(i, 1, index) res = (res*mang[i])%mod;
	
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	ll ans = 0;
	FOR(i, 0, (k-1)) {
		ll p1 = a(k-i, k)*c(k-i+1, n+1);
		p1%=mod;
		
		ll p2 = a(k-1, k)*c(k, n+1);
		p2%=mod;
		
		ll p3 = 1/2*a(2, n+1)*a(2, n+1);
		p3%=mod;
		
		ans = (ans+p1-p2+p3)%mod;
	}
		
	cout << ans << endl;
	return 0;
}
