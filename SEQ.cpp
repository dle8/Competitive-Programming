#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxk 100
#define mod 1000000000
using namespace std;

typedef long long ll;
long n, k;
ll c[maxk], a[maxk];

struct matrix {
	ll dimension[maxk][maxk];
};

matrix mtrix;
matrix mul(matrix a, matrix b) {
	matrix temp;
	
	FOR(i, 1, k)
	FOR(j, 1, k)
	FOR(o, 1, k) temp.dimension[i][j] = (temp.dimension[i][j]+(a.dimension[i][o]*b.dimension[o][j])%mod)%mod;

	return temp;
}

matrix pow(long base) {
	if (base==1) return mtrix;
	matrix root = pow(base/2);
	if (base%2==0) return mul(root, root);
	else return mul(mul(root, root), mtrix);
} 

void initMatrix() {
	FOR(i, 1, k-1)
	FOR(j, 1, k) {
		if (j==(i+1)) mtrix.dimension[i][j] = 1;
		else mtrix.dimension[i][j] = 0;
	}
	
	FOR(i, 1, k) mtrix.dimension[k][i] = c[k+1-i]%mod;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long test;
	ll res;
	cin >> test;
	FOR(o, 1, test) {
		cin >> k;
		FOR(i, 1, k) cin >> a[i];
		FOR(i, 1, k) cin >> c[i];
		
		cin >> n;
		
		matrix finalPow;
		if (n<=k) cout << a[n] << "\n";
		else {
			initMatrix();
			
			matrix finalPow = pow(n-k);
			
			res = 0;
			FOR(i, 1, k) res = (res+(finalPow.dimension[k][i]*a[i])%mod)%mod;
			cout << res << "\n";	
		}
	}
	return 0;
}
