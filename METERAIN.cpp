#include <bits/stdc++.h>
#define maxn 5000+10
using namespace std;

int n, m;
long long x[maxn], y[maxn], a[maxn], b[maxn], c[maxn];

bool between(long long d, long long m, long long c) {
	return ((d<=m && m<=c) || (c<=m && m<=d));
}

bool meteorIn(long long u, long long v) {
	long long fo, f1, f2;
	for (int i=1; i<=n; i++) {
		f1 = a[i]*u+b[i]*v+c[i];
		if (f1==0 && between(x[i], u, x[i+1]) && between(y[i], v, y[i+1])) return false;
	}
	
	for (int i=1; i<=n; i++) 
	{
		f1 = a[i]*u+b[i]*v+c[i];
		for (int j=1; j<=n; j++) {
			f2 = a[i]*x[j] + b[i]*y[j] +c[i];	
			if (f2!=0) {
				if ((f1<0&& f2>0) || (f1>0&&f2<0)) return false;
				else break;		
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long u, v;
	bool in;
	cin >> n;
	for (int i=1; i<=n; i++) cin >> x[i] >> y[i];
	x[n+1] = x[1];
	y[n+1] = y[1];	
	for (int i=1; i<=n; i++) {//a[i], b[i], c[i] is the coefficient of the line connecting (x[1], y[1]) and (x[2], y[2])
		a[i] = y[i] - y[i+1];
		b[i] = x[i+1] - x[i];
		c[i] = x[i]*y[i+1] - x[i+1]*y[i];
//		cout << a[i] << " " << b[i] << " " << c[i] << endl;
	}

	cin >> m;
	for (int i=1; i<=m; i++) {
		in = true;
		cin >> u >> v;
		in = meteorIn(u, v);
		if (in) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
