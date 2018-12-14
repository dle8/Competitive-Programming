#include <bits/stdc++.h>
#define maxn 1000+10
using namespace std;

struct node {
	int v, next;
};

int n;
node graph[2*maxn];
int check[maxn], kq[maxn][3], head[maxn];
/*
thoa man: co 1 dinh ke no thuoc D
duoc chon: dinh do thuoc D
kq[u][0]: u k dc cho va k thoa man
kq[u][1]: u k dc chon nhung van thoa man(do co it nhat 1 thg con dc chon)
kq[u][2]: u dc chon, tuc la u cung thoa man
*/

int min(int a, int b) {
	if (a<=b) return a;
	else return b;
}

void dfs(int u) {
	int v;
	int i = head[u];
	bool isLeaf = true;
	while (i!=0) {
		v = graph[i].v;
		if (check[v]==0) {
			check[v] = u;
			isLeaf = false;
			dfs(v);
		}
		i = graph[i].next;
	}
	
	if (isLeaf) {
		kq[u][1] = 1000000000;
		kq[u][0] = 0;
		kq[u][2] = 1;
		return;
	}
	
	kq[u][2] = 1;
	
	bool flag = false;
	bool flag0 = false;
	int tmin = 1000000000;
	i = head[u];
	while (i!=0) {
		v = graph[i].v;
		if (check[v]==u) {
			if (kq[v][1]==1000000000) flag0 = true;
			else kq[u][0]+=kq[v][1];
			if (kq[v][2]<=kq[v][1]) {
				kq[u][1]+=kq[v][2];
				flag = true;
			}
			else {
				tmin = min(tmin, kq[v][2]-kq[v][1]);
				kq[u][1]+=kq[v][1];
			}
			kq[u][2]+=min(kq[v][0], min(kq[v][1], kq[v][2]));
		}
		i = graph[i].next;
	}
	if (!flag) kq[u][1]+=tmin;
	if (flag0) kq[u][0] = 1000000000;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int u, v, dem;
	while (true) {
		cin >> n;
		if (n==0) break;
		memset(head, 0, sizeof(head));
		memset(check, 0, sizeof(check));
		for (int i=1; i<=n; i++)
			for (int j=0; j<=2; j++) kq[i][j] = 0;
		dem = 0;
		for (int i=1; i<=(n-1); i++) {
			cin >> u >> v;
			dem++;
			graph[dem].v = v;
			graph[dem].next = head[u];
			head[u] = dem;
			
			dem++;
			graph[dem].v = u;
			graph[dem].next = head[v];
			head[v] = dem;
		}
		check[1] = -1;
		dfs(1);
		cout << min(kq[1][1], kq[1][2]) << endl;
	}
	return 0;
}
