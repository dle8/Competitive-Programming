#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 2*8+1
#define eps 1e-6
#define oo 1e9
using namespace std;

long bitOn[maxn], x[maxn], y[maxn], kq[3], n, countBit;
double f[(1<<maxn)];

double min(double a, double b) {
	if (a-b<eps) return a;
	else return b;
}

long getBit(long j, long i) {//get Bit thu j cua i
	return ((i>>(j-1))&1);
}

long setBit(long j, long i) {//tat Bit thu j cua i
	return (i^(1<<(j-1)));
}

double d (long i, long j) {
	return (sqrt(pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2)));
}

void update(long team) {
 	if (kq[1]!=kq[2]) {
 		cout << kq[1] << " " << kq[2] << endl;
		long prevTeam = setBit(kq[1], team);
		prevTeam = setBit(kq[2], team);
		f[team] = min(f[team], f[prevTeam]+d(kq[1], kq[2]));
	}
}

void permutation(long i, long team) {
	if (i>2) {
		update(team);
		return;
	}
	
	FOR(j, i, 2*countBit-2+i) {
		kq[i] = bitOn[j];
		permutation(i+1, team);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long tcase = 0;
	string name;
	while (true) {
		cin >> n;
		if (n==0) break;
		tcase++;
		FOR(i, 1, (2*n)) cin >> name >> x[i] >> y[i];
		
		f[0] = 0;
		FOR(i, 1, (1<<(2*n))-1) {
			countBit = 0;
			FOR(j, 1, (2*n)) 
			if (getBit(j, i)==1) {
				countBit++;
				bitOn[countBit] = j;
			}
			if (countBit%2!=0) continue;
			
			f[i] = oo;
			permutation(1, i);
		}
		
		cout <<  "Case " << tcase << ": " << f[(1<<(2*n))-1] << "\n";
	}
	return 0;
}
