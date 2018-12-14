#include <bits/stdc++.h>
#define	maxn 100000+10
#define eps 1e-9
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

double cup[2*maxn];
long n;
double w;

double min(double a, double b) {
	if (a-b<eps) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> w;
	FOR(i, 1, (2*n)) cin >> cup[i];
	sort(cup+1, cup+1+(2*n));
	
	double k = min(cup[1], (double)(cup[n+1]/2.0));
	
	double res = 3*k*n;
	cout << setprecision(10) << min(res, w);
	
	return 0;
}
