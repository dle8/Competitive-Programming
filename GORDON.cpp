#include <bits/stdc++.h>
using namespace std;

int n;

int min(int a, int b) {
	if (a<=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int inp, pos;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> x[i] >> y[i];
		cin >> s;
		pos = min(s, n-1);
		for (int j=1; j<=pos; j++) cin >> tower[i][j];
		for (int j=pos+1; j<=(n-1); j++) cin >> inp;
	}
	
	for (int i=1; )
	return 0;
}
