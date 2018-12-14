#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define oo 2e9
#define maxn 100000+10
using namespace std;

long n, l, r, tindex, tcount;
map<long, long> anhxa;
long ft[3*maxn], rr[3*maxn], a[maxn], f[maxn];

void add(long x) {
	tindex++;
	rr[tindex] = x;
}

void update(long i) {
	for(; i<=tcount; i+=(i&(-i))) ft[i]++;
}

long long getSum(long i) {
	long long sum = 0;
	for(; i>0; i-=(i&(-i))) sum+=ft[i];
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long last;
	long long res;
	cin >> n >> l >> r;
	
	tindex = 0;
	FOR(i, 1, n) {
		cin >> a[i];
		f[i] = f[i-1] + a[i];
		add(f[i]);
		add(f[i]+l);
		add(f[i]+r);
	}
	
	add(l);
	add(r);
	sort(rr+1, rr+1+tindex);
	
	last = oo;
	tcount = 0;
	FOR(i, 1, tindex) {
		if (rr[i]!=last) {
			last = rr[i];
			tcount++;
		}
		anhxa[rr[i]] = tcount;
	}
	
	res = 0;
	REP(i, n-1, 0) {
		update(anhxa[f[i+1]]);
		res+=getSum(anhxa[f[i]+r]) - getSum(anhxa[f[i]+l]-1);
	}
	
	return cout << res, 0;
}
