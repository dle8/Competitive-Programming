#include <bits/stdc++.h>
#define maxn 200000+10
using namespace std;

typedef long long ll;

ll ft1[maxn], ft2[maxn], a[maxn], s[maxn], e[maxn];
long n;
long it[4*maxn];

void update(long cs, long u, long v, long i) {
	if (i<u || v<i) return;
	it[cs]+=1;
	if (u==v) return;
	long mid = (u+v)/2;
	update(2*cs, u, mid, i);
	update(2*cs+1, mid+1, v, i);
}

long getZero(long cs, long u, long v, long l, long r) {
	if (r<u || v<l) return 0;
	if (l<=u && v<=r) return it[cs];
	long mid = (u+v)/2;
	return getZero(2*cs, u, mid, l, r) + getZero(2*cs+1, mid+1, v, l, r);
}

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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long rangeSum;
	long q;
	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (a[i]==0) update(1, 1, n, i);
		
		for (long temp=i; temp<=n; temp+=(temp&(-temp))) ft1[temp]+=a[i];
	}
	
	for (int i=1; i<=n; i++) 
	if (s[a[i]]==0) s[a[i]] = i;
	
	for (int i=n; i>=1; i--)
	if (e[a[i]]==0) e[a[i]] = i;

	for (int i=q; i>=1; i--) {
		if (s[i]==0 || e[i]==0) continue;
		rangeSum = query(e[i])-query(s[i]-1);
		cout << s[i] << " " << e[i] << " " << rangeSum << "\n";
		if (rangeSum!=(i*(e[i]-s[i]+1-getZero(1, 1, n, s[i], e[i])))) {
			cout << "NO";
			return 0;
		}
		a[s[i]]+=-1;
		a[e[i]]-=-1;
		update(ft1, s[i], -1);
		update(ft1, e[i]+1, 1);
		update(ft2, s[i], (s[i]-1)*-1);
		update(ft2, e[i]+1, -e[i]*-1);
	}
	
	cout << "YES" << "\n";
	for (int i=1; i<=n; i++) a[i]+=a[i-1];
	for (int i=1; i<=n; i++) {
		if (a[i]==0) cout << 1 << " ";
		else cout << a[i] << " ";
	}
	return 0;
}
