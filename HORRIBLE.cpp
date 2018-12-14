#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i=l; i<=r; i++)
#define maxn 100000+10
using namespace std;

typedef long long ll;

long n;
ll ft1[maxn], ft2[maxn];

void update(ll ft[], long i, ll val) {
	for (; i<=n; i+=(i&(-i))) ft[i]+=val;
}

ll query(ll ft[], long i) {//tinh tong cac phan tu tu 1 den i
	ll sum = 0;
	for (;  i>0; i-=(i&(-i))) sum+=ft[i];
	return sum;
}

ll query(long i) {
	return query(ft1, i)*i-query(ft2, i);
}

void process() {
	long c, type, l, r;
	ll v;
	cin >> n >> c;
	FOR(i, 1, n) {
		ft1[i] = 0;
		ft2[i] = 0; 
	}
	FOR(i, 1, c) {
		cin >> type >> l >> r;
		if (type==0) {
			cin >> v;
			update(ft1, l, v);
			update(ft1, r+1, -v);
			update(ft2, l, (l-1)*v);
			update(ft2, r+1, -r*v);
		}
		if (type==1) cout << query(r)-query(l-1) << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long test;
	cin >> test;
	FOR(i, 1, test) process();
	return 0;
}
