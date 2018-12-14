#include <bits/stdc++.h>
#define maxc 1000000000
#define maxn 100+10
using namespace std;

struct node {
	int v, next;
};

int n, s, t, firstDist, secondDist;
bool twoPathExisted, flag;
int c[maxn][maxn], f[maxn][maxn], d[maxn], ftrace[maxn], strace[maxn], res[maxn], head[maxn];
node graph[100*maxn];

void read() {
	int m, u, v, l, dem;
	cin >> n >> m;
	cin >> s >> t;
	for (int i=1; i<=m; i++) {
		cin >> u >> v >> l;
		c[u][v] = l;
		c[v][u] = 0;
	}
}

int findShortestPath(int (&trace)[maxn]) {
	for (int u=1; u<=n; u++) d[u] = maxc;
	d[s] = 0;
	bool found;
	do{
		found = false;
		for(int u=1; u<=n; u++) 
			for (int v=1; v<=n; v++) {
				if ((c[u][v]-f[u][v])!=0) {
					if (d[v]>d[u]+c[u][v]) {
						trace[v] = u;
						d[v] = d[u]+ c[u][v];
						found = true;
					}
				}
			}
	} while (found);
	
	if (d[t]==maxc) return -1;
	else return d[t];
}

void process() {
	int u, v, count;
	
	for (int i=1; i<=n; i++)
		memset(f[i], 0, sizeof(f[i]));
	
	twoPathExisted = false;
	memset(ftrace, 0, sizeof(ftrace));
	memset(strace, 0, sizeof(strace));

	firstDist = findShortestPath(ftrace);
	count = 0;
	v = t;
	ftrace[s] = 0;
	while (v!=0) {
		u = ftrace[v];
		f[u][v]+=c[u][v];
		f[v][u]-=c[u][v];
		count++;
		graph[count].v = v;
		graph[count].next = head[u];
		head[u] = count;
		v = u;
	}	
	
	secondDist = findShortestPath(strace);
	v = t;
	strace[s] = 0;
	while (v!=0) {
		u = strace[v];
		f[u][v]+=c[v][u];
		f[v][u]-=c[v][u];
		count++;
		graph[count].v = v;
		graph[count].next = head[u];
		head[u] = count;
		v = u;
	}
	
	twoPathExisted = ((firstDist!=-1) && (secondDist!=-1));
}

void dfs(int u, int&count) {
	int v;
	int i = head[u];
	count++;
	res[count] = u;
	if (flag) return;
	while (i!=0) {
		int v = graph[i].next;
		if (v==t) {
			flag = true;
			return;
		}
		if ((c[u][v]-f[u][v])!=0 && flag) dfs(v, count);
		i = graph[i].next;
	}
}

void print() {
	int u, v, count;
	int res[maxn];
	if (!twoPathExisted) cout << -1;
	else {
		cout << firstDist + secondDist << "\n";
		count = 0;
		flag = false;
		dfs(s, count);
		cout << count << " ";
		for (int i=1; i<=count; i++) 
			cout << res[i] << " ";
		
		count = 0;
		flag = false;
		dfs(s, count);
		cout << count << " ";
		for (int i=1; i<=count; i++) 
			cout << res[i] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	read();
	process();
	print();
	return 0;
}
