#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define maxn 500+10
using namespace std;

string res, temp;
char a[maxn][maxn];
string f[maxn][maxn];
long m, n;

string max(string a, string b) {
	if (a>=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	
	FOR(i, 1, m)
	FOR(j, 1, n) {
		cin >> a[i][j];
		f[i][j] = "";
	}

	f[1][0] = "";
	FOR(i, 1, n) {
		if (a[1][i]=='2') break;
		f[1][i] = f[1][i-1]+a[1][i];
	}
	
	FOR(i, 2, m)
	FOR(j, 1, n) {
		if (a[i][j]=='2') continue;
		if (j>1) {
			if (a[i-1][j]!='2' && a[i][j-1]!='2') f[i][j] = max(f[i-1][j], f[i][j-1])+a[i][j];
			if (a[i-1][j]=='2' && a[i][j-1]!='2') f[i][j] = f[i][j-1]+a[i][j];
			if (a[i-1][j]!='2' && a[i][j-1]=='2') f[i][j] = f[i-1][j]+a[i][j];
		}
		else {
			if (a[i-1][j]!='2') f[i][j] = f[i-1][j]+a[i][j];	
		}
	}
	
	return cout << f[m][n], 0;
}
