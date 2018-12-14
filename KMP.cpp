#include <bits/stdc++.h>
#define maxn 1000000+10
using namespace std;

string a, x;
long m, n, tnext[maxn];

void init() {
	long j, jj;
	j = 1;
	jj = 0;
	tnext[1] = 0;
	while (j<=n) {
		while (jj>0 && x[j]!=x[jj]) jj = tnext[jj];
		j++;
		jj++;
		if (x[j]==x[jj]) tnext[j] = tnext[jj];
		else tnext[j] = jj;
	}
}

void process() {
	long i, j;
	i = 1;
	j = 1;
	do {
		while (j>0 && x[j]!=a[i]) j = tnext[j];
		i++;
		j++;
		if (j>n) {
			cout << i-j+1 << " ";
			j = tnext[j];
		}
	} while (i<=m);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a;
	cin >> x;
	m = a.length();
	n = x.length();
	
	init();
	process();
	return 0;
}
