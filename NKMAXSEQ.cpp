#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define maxn 50000+10
#define oo 1000000000
using namespace std;

struct nll {
	long val, cs;
};

nll s[maxn];
long a[maxn], n;

bool compare(const nll&a, const nll&b) {
	return (a.val<b.val);
}

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long p, minj, maxLength;
	cin >> n >> p;
	maxLength = -oo;
	FOR(i, 1, n) {
		cin >> a[i];
		s[i].val = s[i-1].val+a[i];
		if (s[i].val>=p) maxLength = max(maxLength, s[i].cs);
		s[i].cs = i;
	}
	
	sort(s+1, s+1+n, compare);
	minj = oo;
	long pointer = 0;
	FOR(i, 1, n+1) {
		FOR(j, pointer+1, i-1) {
			if (s[i].val-s[j].val<p) break;
			minj = min(minj, s[j].cs);
			pointer = j;
		}
		if (minj<s[i].cs) maxLength = max(maxLength, s[i].cs-minj);
	}
	
 	if (maxLength==-oo) cout << -1;
	else cout << maxLength;
	
	return 0;
}
