#include <bits/stdc++.h>
#include <climits>
#define maxn 50000+10
using namespace std;
 
int n;
long it[4*maxn], a[maxn];
 
long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}
 
void update(int cs, int u, int v, int i, long val) {
	if (i<u || v<i) return; //neu i khong nam trong doan [u, v]
	it[cs] = max(it[cs], val);
	if (u==v) return;//khi (u==v) cung chinh la (u==v==i) va day la nut la cua cay
	int mid = (u+v)/2;
	update(2*cs, u, mid, i, val);
	update(2*cs+1, mid+1, v, i, val);
}
 
long getMax(int cs, int u, int v, int l, int r) {
	if (r<u || l>v) return LONG_MIN;
	if (l<=u && v<=r) return it[cs];
	int mid = (u+v)/2;
	return max(getMax(2*cs, u, mid, l, r), getMax(2*cs+1, mid+1, v, l, r));
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, u, v, p;
	long k;
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> u>> v>> k;
		a[u]+=k;
		a[v+1]+=-k;
	}
	
	for (int i=2; i<=n; i++) {
		a[i] = a[i-1]+a[i];
		update(1, 1, n, i, a[i]);
	}
	cin >> p;
	for (int i=1; i<=p; i++) {
		cin >> u >> v;
		cout << getMax(1, 1, n, u, v) << endl;
	}
	return 0;
} 
