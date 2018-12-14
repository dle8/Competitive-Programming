#include <iostream>
#include <stdio.h>
#define maxn 500+10
using namespace std;

int n;
long long d[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, k, tcase, u, v, c, key;
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++) {
			if (i==j) d[i][j] = 0;
			else {
				d[i][j] = 100000000000000000;
				d[j][i] = 100000000000000000;
			}
		}
		
	for (int i=1; i<=m; i++) {
		scanf("%d%d%d", &u, &v, &c);
	//	cin >> u >> v>> c;
		d[u][v] = c;
	}
	
	for (int i=1; i<=k; i++) {//
		scanf("%d", &tcase);
//		cin >> tcase;
		if (tcase==1) {
			scanf("%d", &key);
//			cin >> key;
			for (int u=1; u<=n; u++) {
				for (int v=1;  v<=n; v++) {
					if (d[u][v] > d[u][key] +d[key][v])
						d[u][v] = d[u][key] + d[key][v];
				}
			}
		}
		
		if (tcase==2) {
			scanf("%d%d", &u, &v);
//			cin >> u >> v;
			if (d[u][v]==100000000000000000) cout << -1 << endl;
			else cout << d[u][v] << endl;
		}
	}
	
	return 0;
}
