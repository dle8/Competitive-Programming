#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxk 400+10
#define maxa 40000
using namespace std;

struct node {
	long h, a, c;
	
	bool operator<(const node&p) {
		return (a<p.a);
	}
};

long k, f[4*maxa];
node rock[maxk];

long min(long a, long b){
	if (a<=b) return a;
	return b;
}

long bs(long c, long key) {
	long d = 1;
	while (d<=c) {
		long mid = (d+c)/2;
		if (f[mid]<=key) d = mid+1;
		else c = mid-1;
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long r, anchor;
	cin >> k;
	FOR(i, 1, k) cin >> rock[i].h >> rock[i].a >> rock[i].c;
	sort(rock+1, rock+1+k);
	f[1] = 0;
	r = 1;
	FOR(i, 1, k) {
		if (rock[i].h>rock[i].a) continue;
		anchor = bs(r, rock[i].a-rock[i].h);
		REP(j, anchor, 1) {
			FOR(u, 1, rock[i].c) {
				if (f[j]+u*rock[i].h<=rock[i].a) f[++r] = f[j]+u*rock[i].h;
				else break;
			}
		}
		
		sort(f+1, f+1+r);
	}
	
	cout << f[r];
	return 0;
}
