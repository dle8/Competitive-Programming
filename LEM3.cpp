#include <bits/stdc++.h>
#define maxn 16+5
#define maxc 1000000000
using namespace std;

long c[maxn][maxn], n, d[maxn][70000];

long getBit(long i, long x) {
	return ((x>>(i-1))&1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long min = maxc;
	cin >> n;
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++) cin >> c[i][j];
	
	for (int x=1; x<(1<<n); x++)
	for (int i=1; i<=n; i++) d[i][x] = maxc;
	
	for (int i=1; i<=n; i++) d[i][1<<(i-1)] = 0;
	
	for (int x=1; x<(1<<n); x++)
	for (int i=1; i<=n; i++) {
		if (getBit(i, x)==0) continue;
		for (int j=1; j<=n; j++)
			if (getBit(j, x)==1 && d[i][x]>d[j][x^(1<<(i-1))]+c[j][i])
			d[i][x] = d[j][x^(1<<(i-1))] + c[j][i];
	}
	
	for (int i=1; i<=n; i++)
	if (min>d[i][(1<<n)-1]) min = d[i][(1<<n)-1];
	cout << min;
	return 0;
}


