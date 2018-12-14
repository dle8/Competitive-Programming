#include <bits/stdc++.h>
#define maxn 300000+10
#define maxc 1000000000000000
using namespace std;

typedef long long ll;

struct node {
	long time = 0;
	ll val = 0;
};

node f[maxn][3];
ll sum[maxn][3];
long a[3][maxn];
long n;

ll max(ll a, ll b) {
	if (a>=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long t;
	ll temp, res, sumUp, sumDown;
	cin >> n;
	for (int i=1; i<=2; i++)
	for (int j=1; j<=n; j++) 
		cin >> a[i][j];
		
	f[1][1].time = 0;
	f[1][1].val = 0;
	f[1][2].time = 1;
	f[1][2].val = a[2][1];
	
	for (int i=1; i<=n-1; i++) {
		f[i+1][2].val = max(f[i][1].val+a[1][i]*(f[i][1].time+1)+a[2][i]*(f[i][1].time+2), f[i][2].val+a[2][i]*(f[i][2].time+1));
		if (f[i+1][2].val == f[i][2].val+a[2][i]*(f[i][2].time+1)) f[i+1][2].time = f[i][2].time+1;
		else f[i+1][2].time = f[i][1].time+2;
		
		f[i+1][1].val = max(f[i][2].val+a[2][i]*(f[i][2].time+1)+a[1][i]*(f[i][2].time+2), f[i][1].val+a[1][i]*(f[i][1].time+1));
		if (f[i+1][1].val==f[i][1].val+a[1][i]*(f[i][1].time+1)) f[i+1][1].time = f[i][1].time+1;
		else f[i+1][1].time = f[i][2].time+2;
	}
	
	for (int i=1; i<=n; i++) {
		sumUp+=a[1][i]*(i-1);
		sumDown+=a[2][i]*i;
	}
	
	for (int i=1; i<=n; i++) {
		sumUp+=a[2][n-i+1]*(n+i-1);
		if (i!=n) sumDown+=a[1][n-i+1]*(n+i);
	}
	
	sum[1][1] = sumUp;
	sum[1][2] = sumDown;
	
	for (int i=2; i<=n; i++) {
		for (int j=1; j<=2; j++) {
			temp = f[i-1][j].val+sum[i-1][j]-a[j][i]*f[i][j].time;
			if (f[i][j].time==f[i-1][j].time+1) sum[i][j] = temp;
			else sum[i][j] = temp-a[3-j][i]*(f[i][3-j].time+1);	
		}
	}
	
	res = -maxc; 
	for (int i=1; i<=2; i++) 
	for (int j=1; j<=n; j++)
		res = max(res, max(f[j][i].val, sum[j][i]));	
	
	cout << res;
	return 0;
}
