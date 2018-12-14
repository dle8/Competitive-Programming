#include <bits/stdc++.h>
#define maxc 1000000000
#define maxn 16+5
using namespace std;

long w[maxn];

int getBit(int k, int x) {//get bit thu k cua x
	return (x>>(k-1)&1);
}

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long c, n, res, sum;
	cin >> c >> n;
	for (int i=1; i<=n; i++)
		cin >> w[i];
	
	res = -maxc;
	
	for (int i=0; i<(1<<n); i++) {
		sum = 0;
		for (int j=1; j<=n; j++) 
			if (getBit(j, i)==1) sum+=w[j];
		if (sum<=c) res = max(res, sum);
	}

	cout << res;
	return 0;
}
