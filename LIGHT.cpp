#include <bits/stdc++.h>
#define maxm 10000+10
#define maxn 100+10
#define maxc 1000000000
using namespace std;

long m, n, trace[2*maxn], a[maxn], b[maxn], f[2*maxn][2*maxn], c[2*maxn][2*maxn];
bool check[2*maxn];

long min(long a, long b) {
	if (a<b) return a;
	else return b;
}

void bfs(long u) {
	long first = 1, last = 1;
	bool zeroCounted = false;
	long Queue[2*maxn];
	Queue[1] = u;
	while (first<=last) {
		long v = Queue[first];
		first++;
		for (int k=0; k<=(m+n+1); k++)
			if (check[k] && trace[k]==0 && (c[v][k]-f[v][k]>0)) {
				trace[k] = v;
				check[k] = false;
				if (k==(m+n+1)) return;
				last++;
				Queue[last] = k;
			}
	}
}

void findFlow() {
	long flow, res, temp;
	while (true) {
		memset(trace, 0, sizeof(trace));
		memset(check, true, sizeof(check));
		bfs(0);
		if (trace[m+n+1]==0) break;
		temp = (m+n+1);
		flow = maxc;
		while (temp!=0) {
			flow = min(flow, c[trace[temp]][temp]-f[trace[temp]][temp]);
			temp = trace[temp];
		}
		
		temp = (m+n+1);
		while (temp!=0) {
			f[trace[temp]][temp]+=flow;
			f[temp][trace[temp]]-=flow;
			temp = trace[temp];
		}
	}
	
	res = 0;
	for (int i=1; i<=m; i++) 
	if (f[0][i]>0) res+=f[0][i];
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long count, k, u, v;
	cin >> m >> n >> k;
	for (int i=1; i<=m; i++) cin >> a[i];
	for (int i=1; i<=n; i++) cin >> b[i];
	//0 la dinh phat
	//m+n+1 la dinh thu
	for (int i=1; i<=k; i++) {
		cin >> u >> v;
		c[0][u] = a[u];
		c[u][v+m] = maxc;
		c[v+m][m+n+1] = b[v]; 
	}
	findFlow();
	return 0;
}
