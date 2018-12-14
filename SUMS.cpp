#include <bits/stdc++.h>
#define maxn 5000+10
#define maxa1 50000+10
#define maxc 1000000000000
using namespace std;

long n, a[maxn], m;
long long d[maxa1],f[maxa1],Stack[maxa1];
bool check[maxa1];

long long min (long long a, long long b)
{
	if (a>b) return b;
	else return a;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long num, r;
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	
	memset(check, true, sizeof(check));
	check[0] = false;
	for (int i=1; i<a[1]; i++) f[i] = maxc;
	for (int i=2; i<=n; i++) {
		long temp=0;
		for (int j=1; j<=(a[1]-1); j++) {
			temp=(temp+a[i])%a[1];
			f[temp]=min(f[temp],a[i]*j);
		}
	}
	
	memset(check,true,sizeof(check));
	for (int i=1; i<a[1]; i++) d[i] = maxc;
	int top=1;
	Stack[1]=0;
	check[0]=false;
	d[0] = 0;
	
	for (int i=0; i<a[1]; i++) 
	if (f[i]!=maxc)
	{
		for (int j=1; j<=top; j++){
			int bien=(Stack[j]+i)%a[1];
			if (d[Stack[j]]+f[i]<d[bien]) {
				d[bien] = d[Stack[j]] + f[i];
				if (check[bien]) {
					top++;
					Stack[top]=bien;
					check[bien]=false;
				}
			}
		}
	}
	
	cin >> m;
	for (int i=1; i<=m; i++) {
		cin >> num;
		if (d[num%a[1]]==maxc) cout << "NIE" << "\n";
		else {
			if (num>=d[num%a[1]]) cout << "TAK" << "\n";
			else cout << "NIE"<< "\n";	
		}
	}
	return 0;
}
