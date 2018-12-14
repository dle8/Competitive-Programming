#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
using namespace std;

const int oo = 1e9;	

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

void updateSum(long cs, long u, long v, long i, long val) {
	if (i<u || v<i) return;
	it[cs]+=val;
	if (u==v) return;
	long mid = (u+v)/2;
	update(2*cs, u, mid, i, val);
	update(2*cs+1, mid+1, v, i, val);
}

long getITSum(long cs, long u, long v, long l, long r) {
	if (r<u || v<l) return 0;
	if (l<=u && v<=r) return it[cs];
	long mid = (u+v)/2;
	return getITSum(2*cs, u, mid, l, r) + getITSum(2*cs+1, mid+1, v, l, r);
}

void updateMax(long cs, long u, long v, long i, long val) {
	if (i<u || v<i) return;
	it[cs] = max(it[cs], val);
	if (u==v) return;
	long mid = (u+v)/2;
	update(2*cs, u, mid, i, val);
	update(2*cs+1, mid+1, v, i, val);
}

long getITMax(long cs, long u, long v, long l, long r) {
	if (r<u || v<l) return -oo;
	if (l<=u && v<=r) return it[cs];
	long mid = (u+v)/2;
	return max(getITMax(2*cs, u, mid, l, r), getITMax(2*cs+1, mid+1, v, l, r));
} 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//implement
	return 0;
}
