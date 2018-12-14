#include <bits/stdc++.h>
#define maxn 1000+10
#define maxc 1000000000
using namespace std;

struct node {
	long v, next;
};

long n, height[maxn], euler[10*maxn], head[maxn], fa[maxn];
long it[10000+10];
node graph[maxn];

long min(long a, long b) {
	if (height[a]<height[b]) return a;
	else return b;
}

void update(long cs, long u, long v, long i) {
	if (i<u || v<i) return;
	it[cs] = min(it[cs], euler[i]);
	if (u==v) return;
	long mid = (u+v)/2;
	update(2*cs, u, mid, i);
	update(2*cs+1, mid+1, v, i);
}

long getLca(long cs, long u, long v, long l, long r) {
	if(r<u || v<l) return 0;
	if (l<=u && v<=r) return it[cs];
	long mid = (u+v)/2;
	long left = getLca(2*cs, u, mid, l, r);
	long right = getLca(2*cs+1, mid+1, v, l, r);
	return min(left, right);
}

void dfs(long u, long &count) {
	long v;
	long i = head[u];
	count++;
	fa[u] = count;
	euler[count] = u;
	while (i!=0) {
		v = graph[i].v;
		height[v] = height[u]+1;
		dfs(v, count);
		count++;
		euler[count] = u;
		i = graph[i].next;
	}
	count++;
	euler[count] = u;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long test, count, v, s, t, m, q;
	cin >> test;
	for (int i=1; i<=test; i++) {
		cin >> n;
		count = 0;
		memset(head, 0, sizeof(head));
		memset(it, 0, sizeof(it));
		for (int u=1; u<=n; u++) {
			cin >> m;
			for (int k=1; k<=m; k++) {
				cin >> v;
				count++;
				graph[count].v = v;
				graph[count].next = head[u];
				head[u] = count;
			}
		}
		cout << "Case " << i << ":" << "\n";
		count = 0;
		height[1] = 1;
		height[0] = maxc;
		dfs(1, count);
		for (int j=1; j<=count; j++) update(1, 1, count, j);
		
		cin >> q;
		for (int j=1; j<=q; j++) {
			cin >> s >> t;
			if (fa[s]<fa[t]) cout << getLca(1, 1, count, fa[s], fa[t]) << "\n";
			else cout << getLca(1, 1, count, fa[t], fa[s]) << "\n";
		}
	}
	return 0;
}
