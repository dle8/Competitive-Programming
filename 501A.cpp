#include <bits/stdc++.h>
#define maxn 100+10
using namespace std;

int res[maxn], a[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, count, l, r;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> l >> r;
		a[l]+=1;
		a[r+1]-=1;
	}
	for (int i=2; i<=m; i++) {
		a[i]=a[i-1]+a[i];
	}

	count = 0;
	for (int i=1; i<=m; i++)
		if (a[i]==0) {
			count++;
			res[count] = i;
		}
		
	cout << count << "\n";
	for (int i=1; i<=count; i++)
		cout << res[i] << " ";
	return 0;
}
