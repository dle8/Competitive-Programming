#include <bits/stdc++.h>
#define maxn 100+10
using namespace std;

char c[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int r, n, result;
	cin >> r >> n;
	
	for (int i=1; i<=r; i++) 
		for (int j=1; j<=n; j++) cin >> c[i][j];

	for (int i=1; i<=r; i++) c[i][0] = '.';
	for (int j=1; j<=n; j++) c[0][j] = '.';
	
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=n; j++) {
			if (c[i][j]=='#' && (c[i-1][j]=='.' && c[i][j-1]=='.')) result++;
		}
	}

	cout << result;
	return 0;
}
