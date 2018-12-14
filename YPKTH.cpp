#include <bits/stdc++.h>
#define maxn 100000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define oo 1000000000
using namespace std;

struct command {
	long l, r, k, pos;
};

struct node {
	long min = oo;
	long max = -oo;
};

node it[4*maxn];
command cmd[maxn];
long res[maxn], ft[maxn], pos[maxn], a[maxn], n, roirac[maxn], rroirac[maxn];

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

void update(long cs, long u, long v, long i, long val) {
	if (i<u || v<i) return;
	it[cs].min = min(it[cs].min, val);
	it[cs].max = max(it[cs].max, val);
	if (u==v) return;
	long mid = (u+v)/2;
	update(2*cs, u, mid, i, val);
	update(2*cs+1, mid+1, v, i, val);
}

node getBound(long cs, long u, long v, long x, long y) {
	node temp;
	if (y<u || v<x) return temp;
	if (x<=u && v<=y) return it[cs];
	long mid = (u+v)/2;
	node left = getBound(2*cs, u, mid, x, y);
	node right = getBound(2*cs+1, mid+1, v, x, y);
	temp.min = min(left.min, right.min);
	temp.max = max(left.max, right.max);
	return temp;
}

void update(long i, long val) {
	for(; i<=n; i+=(i&(-i))) ft[i]=val;
}

long getSum(long i) {
	long sum = 0;
	for(; i>0; i-=(i&(-i))) sum+=ft[i];
	return sum;
}

void swap(long&a, long&b) {
	long temp = a;
	a = b;
	b = temp;
}

void qs(long dau, long cuoi) {
	long i = dau;
	long j = cuoi;
	long mid = a[(dau+cuoi)/2];
	
	do{
		while (a[i]<mid) i++;
		while (a[j]>mid) j--;
		if (i<=j) {
			swap(a[i], a[j]);
			swap(pos[i], pos[j]);
			i++;
			j--;
		}
	} while (i<=j);
	
	if (i<cuoi) qs(i, cuoi);
	if (dau<j) qs(dau, j);
}

bool ascend(const command&a, const command&b) {
	return ((a.l<b.l) || (a.l==b.l && a.r<b.r));
}

long getSum(long u, long v) {
	return getSum(v)-getSum(u-1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long q, last, count;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	
	qs(1, n);
	last = oo;
	count = 0;
	FOR(i, 1, n) {
		if (a[i]!=last) {
			last = a[i];
			count++;
		}
		roirac[pos[i]] = count;
		rroirac[count] = pos[i];
		update(1, 1, n, pos[i], count);
	}
	
	cin >> q;
	FOR(i, 1, q) {
		cin >> cmd[i].l >> cmd[i].r >> cmd[i].k;
		cmd[i].pos = i;
	}
	
	sort(cmd+1, cmd+1+q, ascend);
	
	cmd[0].l = 1;
	cmd[0].r = cmd[1].l;
	
	FOR(i, 1, q) {
		node bound = getBound(1, 1, n, cmd[i].l, cmd[i].r);
		FOR(j, cmd[i-1].l, cmd[i].l-1) update(roirac[j], 0);
		FOR(j, cmd[i-1].r+1, cmd[i].r) update(roirac[j], 1);
		FOR(j, cmd[i].r+1, cmd[i-1].r) update(roirac[j], 0);
		
		long d = bound.min;
		long c = bound.max;
		
		while (d<=c) {
			long mid = (d+c)/2;
			if (getSum(bound.min, mid)<cmd[i].k) d = mid+1;
			else c = mid-1;
		}
		
		res[cmd[i].pos] = rroirac[d];
	}
	
	FOR(i, 1, q) cout << res[i] << "\n";
	return 0;
}
