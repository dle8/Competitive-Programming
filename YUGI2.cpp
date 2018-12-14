#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 200+10
using namespace std;
 
long a[maxn][maxn], n, k, lab[maxn];
bool check[maxn];
 
long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}
 
long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

long getRoot(long u) {
	if (lab[u]<0) return u;
	lab[u] = getRoot(lab[u]);
	return lab[u];
}

void dsu(long r1, long r2) {
	if (lab[r1]==lab[r2]) {
		lab[r1]--;
		lab[r2] = r1;
		return;
	}
	if (lab[r1]<lab[r2]) lab[r2] = r1;
	else lab[r1] = r2;
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long maxc, d, c, mid, team, minc, r1, r2;
	cin >> n >> k;
	maxc = 0;
	FOR(i, 1, n)
	FOR(j, 1, n) {
		cin >> a[i][j];
		maxc = max(maxc, a[i][j]);
		minc = min(minc, a[i][j]);
	}
	
	d = minc;
	c = maxc;
	
	while (d<=c) {
		mid = (d+c)/2;
		
		FOR(i, 1, n) lab[i] = -1;
		FOR(i, 1, n)
		FOR(j, 1, n) 
		if (a[i][j]<mid && i!=j) {
			r1 = getRoot(i);
			r2 = getRoot(j);
			if (r1!=r2) dsu(r1, r2);
		}
		
		team = 0;
		memset(check, true, sizeof(check));
		FOR(i, 1, n) {
			r1 = getRoot(i);
			if (check[r1]) {
				check[r1] = false;
				team++;
			}
		}
		
		if (team>=k) d = mid+1;
		else c = mid-1;
	}
	
	cout << c;
	
	return 0;
} 
