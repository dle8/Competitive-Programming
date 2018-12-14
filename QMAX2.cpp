#include <bits/stdc++.h>
#include <climits>
#define maxn 50000+10
#define maxm 100000+10
using namespace std;

int n;
int it[4*maxn], t[4*maxn];

int max(int a, int b) {
	if (a>=b) return a;
	else return b;	
}

void update(int cs, int u, int v, int l, int r, int val) {//tang doan l, r trong (u, v) len val
	if (r<u || v<l) return;
	if (l<=u && v<=r) {
		t[cs]+=val;
		return;
	}
	int mid = (u+v)/2;
	update(2*cs, u, mid, l, r, val);
	update(2*cs+1, mid+1, v, l, r, val);
	it[cs] = max(it[2*cs]+t[2*cs], it[2*cs+1]+t[2*cs+1]);
}

int getMax(int cs, int u, int v, int l, int r) {
	if (r<u || v<l) return LONG_MIN;
	if (l<=u && v<=r) return it[cs]+t[cs];
	int mid = (u+v)/2;
	return (max(getMax(2*cs, u, mid, l, r), getMax(2*cs+1, mid+1, v, l, r))+t[cs]); 
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, tcase, u, v, c;
	cin >> n >> m;
	memset(t, 0, sizeof(t));
	for (int i=1; i<=m; i++) {
		cin >> tcase;
		if (tcase==0) {
			cin >> u >> v >> c;
			update(1, 1, n, u, v, c);
		}
		if (tcase==1) {
			cin >> u >> v;
			cout << getMax(1, 1, n, u,v);
		}
	}
	return 0;
}
