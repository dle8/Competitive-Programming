#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define maxn 100000+10
using namespace std;

long lab[maxn], boxRoot[maxn], n, q;

long getBox(long u) {
	if (lab[u]>0) {
		lab[u] = getBox(lab[u]);
		return lab[u];
	}
	return lab[u];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long s, t, r1, r2;
	cin >> n >> q;
	FOR(i, 1, n)  {
		lab[i] = -i;
		boxRoot[i] = i;
	}
	FOR(i, 1, q) {
		cin >> s >> t;
		r1 = boxRoot[s];//lay root cua hop s
		r2 = boxRoot[t];//lay root cua hop t
		boxRoot[s] = 0;
		if (r2==0) {
			boxRoot[t] = r1;
			lab[r1] = -t;	
		}
		else lab[r1] = r2;
	}
	
	FOR(i, 1, n) cout << -getBox(i) << " ";
	return 0;
}
