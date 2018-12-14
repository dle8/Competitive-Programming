#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define oo 1000000000000000000
#define maxn 200000+10
using namespace std;

typedef long long ll;
map<ll, ll> roirac;
ll it[4*2*maxn], f[maxn], t, mang[2*maxn];
long rr, n, a[maxn];

void update(long cs, long u, long v, long i) {
	if (i<u || v<i) return;
	it[cs]++;
	if (u==v) return;
	long mid = (u+v)/2;
	update(2*cs, u, mid, i);
	update(2*cs+1, mid+1, v, i);
}

ll getSum(long cs, long u, long v, long l, long r) {
	if (r<u || v<l) return 0;
	if (l<=u && v<=r) return it[cs];
	long mid = (u+v)/2;
	return getSum(2*cs, u, mid, l, r) + getSum(2*cs+1, mid+1, v, l, r);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long index;
	ll last;
	cin >> n >> t;
	f[0] = 0;
	index = 0;
	t--;
	FOR(i, 1, n) {
		cin >> a[i];
		f[i] = f[i-1] + a[i];
		mang[++index] = f[i];
		mang[++index] = f[i]+t;
	}
	
	mang[++index] = t;
	sort(mang+1, mang+1+index);
	last = oo;
	rr = 0;	
	FOR(i, 1, index) {
		if (mang[i]!=last) {
			last = mang[i];
			roirac[mang[i]] = ++rr;
		}
	}
	
	ll res = 0, temp;
	REP(i, n-1, 0) {
		update(1, 1, rr, roirac[f[i+1]]);
		res+=getSum(1, 1, rr, 1, roirac[f[i]+t]);
	}
	
	return cout << res, 0;
}
