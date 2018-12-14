#include <iostream>
#include <math.h>
#include <algorithm>
#define maxn 16+5
using namespace std;

long n, k;
long long d[maxn][70000], s[maxn];

int getBit(int i, int x) {//get bit thu i cua j
	return (x>>(i-1))&1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long res;
	cin >> n >> k;
	for (int i=1; i<=n; i++) cin >>s[i];
	
	for (int i=1; i<=n; i++) d[i][1<<(i-1)] = 1;
	
	for (int x=1; x<(1<<n);x++)
	for (int i=1; i<=n; i++) {
		if (getBit(i, x)==0) continue;
		for (int j=1; j<=n; j++)
			if (getBit(j, x)==1 && abs(s[j]-s[i])>k)
			d[i][x] += d[j][x^(1<<(i-1))];
	}
	res = 0;
	for (int i=1; i<=n; i++) res+=d[i][(1<<n)-1];
	cout << res;
	return 0;
}
