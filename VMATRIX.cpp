#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 1000+10
#define mod 10
#define testTimes 6
using namespace std;

long n;
long a[maxn][maxn], b[maxn][maxn], c[maxn][maxn], frei[maxn][maxn];

//dung giai thuat freivalds sinh ra random ma tran v[N*1] gom 0, 1
void createFreivalds() {
	FOR(i, 1, n) frei[i][1] = rand()%2;
}

void read(long (&f)[maxn][maxn]) {
	string input;
	FOR(i, 1, n) {
		cin >> input;
		FOR(j, 1, n) f[i][j-1] = input[j-1]-'0';
	}
}

void mul(long (&f)[maxn][maxn], long x[maxn][maxn], long y[maxn][maxn], long m, long common, long p) {
	FOR(i, 1, m)
	FOR(j, 1, p)
	FOR(k, 1, common) {
		f[i][j] = 0;
		f[i][j] = (f[i][j] + (x[i][k]*y[k][j])%mod)%mod;	
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long test;
	long sub1[maxn][maxn];
	long sub2[maxn][maxn];
	cin >> test;
	FOR(o, 1, test) {
		cin >> n;
		read(a);
		read(b);
		read(c);
		
		bool equal = true;
		FOR(i, 1, testTimes) {
			createFreivalds();
			
			mul(sub1, b, frei, n, n, 1);
			mul(sub2, a, sub1, n, n, 1);
			mul(sub1, c, frei, n, n, 1);
			
			FOR(i, 1, n) 
			if ((sub1[i][1]-sub2[i][1])!=0) equal = false;
		}
		if (equal) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}
