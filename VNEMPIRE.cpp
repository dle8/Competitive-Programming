#include <bits/stdc++.h>
#include <algorithm>
#define maxn 100000+10
using namespace std;

int n;
int lab[maxn], x[maxn], y[maxn], z[maxn];

int getRoot(int u) {
	if (lab[u]>0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	return u;
}

void disjointSet(int r1, int r2) {
	if (lab[r1]==lab[r2]) {
		lab[r1]--;
		lab[r2] = r1;
		return;
	}	
	if (lab[r1]<lab[r2]) lab[r2] = r1;
	else lab[r1] = r2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> x[i], y[i], z[i];
	sort(x+1, x+n+1);
	sort(y+1, y+n+1);
	sort(z+1, z+n+1);
	for (int i=1; i<=n; i++) lab[i] = -1;
	
	return 0;
}
