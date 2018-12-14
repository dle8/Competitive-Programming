#include <bits/stdc++.h>
#define maxm 600000+10
#define maxn 1000+10
using namespace std;
 
struct node {
	int v, next;
};
 
node graph[maxm];
int n;
int a[maxn][maxn], trace[maxn], head[maxn];
bool flag;
 
int main() {
	ifstream cin("nktrio.inp");
	ofstream cout("nktrio.ans");
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int dem = 0;
	
	cin >> n;
	memset(head, 0, sizeof(head));
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) {
			cin >> a[i][j];
			if (a[i][j]==1) {
				dem++;
				graph[dem].v = j;
				graph[dem].next = head[i];
				head[i] = dem;
			}
		}
	
	flag = false;
	for (int u=1; u<=n; u++) {
		int i = head[u];
		if (flag) break;
		while (i!=0) {
			int v = graph[i].v;
			if (flag) break;
			int j = head[v];
			while (j!=0) {
				int k = graph[j].v;
				if (flag) break;
				if (a[k][u]==1){
					cout << u << " " << v <<" "<< k;
					flag = true;
				}
				j = graph[j].next;
			}
			i = graph[i].next;
		}
	}
	if (!flag) cout << -1 << " " << -1 << " " << -1;
	return 0;
} 
