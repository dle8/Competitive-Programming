#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define maxn 200000+10
#define maxh 500000+10
#define oo 1e9
using namespace std;

long n, h, a[maxh], res, w[maxn], tcount;

long min(long x, long y) {
	if (x<=y) return x;
	else return y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> h;
	FOR(i, 1, n) {
		cin >> w[i];
		if (i%2!=0) {
			a[0]+=1;
			a[w[i]+1]-=1;
		}
		else {
			a[h+1]-=1;
			a[h-w[i]]+=1;
		}
	}

	res = a[0];
	FOR(i, 1, h) {
		a[i]+=a[i-1];
		res = min(res, a[i]);
	}
	
	tcount = 0;
	FOR(i, 0, h) if (a[i]==res) tcount++;
	cout << res << " " << tcount;
	return 0;
}
