#include <iostream>
#include <string.h>
#define maxn 100+10
#define maxc 1000000000
using namespace std;

long n, m, s, t, d[maxn], path[3], sl, c[maxn][maxn], res[maxn], trace[maxn], roundQueue[maxn];
bool check[maxn][maxn], flag, inQueue[maxn];

long getDirection(bool direction) {
	if (direction) return -1;
	return 1;
}

long fbm() {
	long first = 0, last = 0, u;
	for (int i=1; i<=n; i++) d[i] = maxc;
	d[s] = 0;
	memset(inQueue, false, sizeof(inQueue));
	roundQueue[0] = s;
	inQueue[s] = true;
	while (first!=(last+1)%n) {
		u = roundQueue[first];
		first = (first+1)%n;
		inQueue[u] = false;
		for (int v=1; v<=n; v++) {
			if (!check[u][v] && d[v]>d[u]+c[u][v]*getDirection(check[v][u])) {
				d[v] = d[u]+c[u][v]*getDirection(check[v][u]);
				trace[v] = u;
				if (!inQueue[v]) {
					last=(last+1)%n;
					roundQueue[last] = v;
					inQueue[v] = true;
				}
			}
		}
	}
	if (d[t]==maxc) return -1;//neu k tim dc duong di
	else return d[t];
}

void dfs(long u, long&sl) {
	sl++;
	res[sl] = u;
	if (u==t) {
		flag = true;
		return;
	}
	for (int v=1; v<=n; v++) {
		if (check[u][v]) {
			check[u][v] = false;
			dfs(v, sl);
		}
		if (flag) return;
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v, l, totalPath;
	cin >> n >> m >> s >> t;
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++) {
		if (i==j) c[i][j] = 0;
		else c[i][j] = maxc;
	}
	for (int i=1; i<=m; i++) {
		cin >> u >> v >> l;
		c[u][v] = l;
		c[v][u] = l;
	}
	memset(trace, 0, sizeof(trace));
	for (int i=1; i<=n; i++) memset(check[i], false, sizeof(check[i]));
	totalPath = 0;
	for (int i=1; i<=2; i++) {
		path[i] = fbm();
		if (path[i]==-1) {
			cout <<-1;
			return 0;
		}
		totalPath+=path[i];
		//sua sai
		v = t;
		while (trace[v]!=0) {
			u = trace[v];
			if (check[v][u]) check[v][u] = false;//neu chieu nguoc lai da di thi bo chon 2 ca chieu
			else check[u][v] = true;//neu chieu nguoc lai (v, u) chua di thi danh dau la da di chieu (u,v)
			v= u;
		}
	}
	
	cout << totalPath << "\n";
	
	for (int i=1; i<=2; i++) {
		sl = 0;
		flag = false;
		dfs(s, sl);
		cout << sl << " ";
		for (int j=1; j<=sl; j++) cout << res[j] << " ";
		cout << "\n";
	}
	
	return 0;
}
