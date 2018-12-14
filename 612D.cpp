#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 1000000+10
#define l first
#define r second
#define oo 1e9+10

using namespace std;

typedef pair<long, long> pll;

pll ranges[maxn], res[maxn], rrange[maxn];
long q[maxn], n, k, tindex;

bool cmpEnd(const pll&x, const pll&y) {
	return (x.r<y.r);
}

bool cmpStart(const pll&x, const pll&y) {
	return (x.l<y.l);
}

long bs(long d, long c, long key) {//tim thg cuoi cung <=key
	long mid;
	while (d<=c) {
		if (d==c) return d;
		mid = (d+c)/2;
		if (rrange[mid].l<=key) d = mid+1;
		else c = mid-1;		
	}
	return c;
}

long findMaxR(long cs, long val) {
	while (true) {
		if (cs==tindex || rrange[cs+1].l>val) break;
		cs = bs(cs+1, tindex, val);
		val = rrange[cs].r;
	}
	return rrange[cs].r;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	FOR(i, 1, n) cin >> ranges[i].l >> ranges[i].r;
	
	sort(ranges+1, ranges+1+n, cmpEnd);
	
	long first = 1;
	long last = 0;
	REP(i, n, n-k+2) q[++last] = ranges[i].l;
	sort(q+first, q+last+1, greater<int>());
	
	REP(i, n-k+1, 1) {
		while (ranges[i].r<q[first] && first<=last) first++;
		q[++last] = ranges[i].l;
		if (last-first+1<k) continue;
		sort(q+first, q+last+1, greater<int>());

		tindex++;
		rrange[tindex].l = max(ranges[i].l, q[last-k+1]); //thg gan dau doan nhat ma van dc cover boi it nhat k segments
		rrange[tindex].r = ranges[i].r;
	}
	
	sort(rrange+1, rrange+1+tindex, cmpStart);
	
	long count = 0;
	res[0].r = -oo;
	rrange[tindex+1].l = oo;

	FOR(i, 1, tindex) {
		if (rrange[i].l<=res[count].r) continue;
		count++;
		res[count].l = rrange[i].l;
		res[count].r = findMaxR(i, rrange[i].r);
	}
	
	cout << count << "\n";
	FOR(i, 1, count) cout << res[i].l << " " << res[i].r << "\n";
	return 0;
}
