#include <iostream>
#define maxm 8000+10
#define maxn 500+10
#define maxc 1000000000
using namespace std;

struct node {
	long v, c, next;
};

node graph[2*maxm];
long p, q, m;
long f[maxn], c[maxn][maxn];

void process() {
	for (int k=1; k<=p; k++)
	for (int u=1; u<=p; u++)
	for (int v=1; v<=p; v++) 
		if (c[u][v]>c[u][k]+c[k][v]) c[u][v] = c[u][k]+c[k][v];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	bool flag;
	long sum, minSum, res, u, v;
	cin >> p >> q >> m;
	for (int i=1; i<=q; i++) cin >> f[i];
	for (int i=1; i<=p; i++)
		for (int j=1; j<=p; j++){
			if (i==j) c[i][j] = 0;
			else c[i][j] = maxc;
		}
	for (int i=1; i<=m; i++) {
		cin >> u >> v;
		cin >> c[u][v];
		c[v][u] = c[u][v];	
	}
	process();
	minSum = maxc;
	for (int i=p; i>=1; i--){
		sum = 0;
		flag = true;
		for (int j=1; j<=q; j++){
			if (c[i][f[j]]==maxc) flag = false;
			if (flag) sum+=c[i][f[j]];
			else break;
		}
		if (flag && minSum>=sum) {
			minSum = sum;
			res = i;
		}
	}
	cout << res;
	return 0;
}
