#include <bits/stdc++.h>
#define maxn 100000+10
using namespace std;

int n, m;
int it[4*maxn], t[4*maxn];

void update(int cs, int u, int v, int l, int r) {
	int p1, p2;
	if (r<u || v<l) return;
	if (l<=u && r>=v) {
		t[cs]=1-t[cs];
		return;
	}
	int mid = (u+v)/2;
	update(2*cs, u, mid, l, r);
	update(2*cs+1, mid+1, v, l, r);
	/*if (t[2*cs]!=0) p1 = (mid-u+1-it[2*cs]);
	else p1 = it[2*cs];
	if (t[2*cs+1]!=0) p2 = (v-mid-1+1-it[2*cs+1]);
	else p2 = it[2*cs+1];
	it[cs] = p1+p2;*/
	
	it[cs] = t[2*cs]*(mid-u+1) + (1-2*t[2*cs])*it[2*cs];
	it[cs]+= t[2*cs+1]*(v-mid-1+1) + (1-2*t[2*cs+1])*it[2*cs+1];
}

int count(int cs, int u, int v, int l, int r, int status) {
	if (r<u || v<l) return 0;
	if (l<=u && v<=r) {
		if ((status ^ t[cs])==0) return (v-u+1-it[cs]);
		else return it[cs];
	}
	
	int mid = (u+v)/2;
	int lightOn = count(2*cs, u, mid, l, r,status ^ t[cs]) + count(2*cs+1, mid+1, v, l, r,status ^ t[cs]);
	return lightOn;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tcase, u, v;
	cin >> n>> m;
	memset(t, 0, sizeof(t));
	memset(it, 0, sizeof(it));
	for (int i=1; i<=m; i++) {
		cin >> tcase >> u >> v;
		if (tcase == 0) update(1, 1, n, u, v);
		else cout << count(1, 1, n, u, v,1) << endl;
	}
	return 0;
}
