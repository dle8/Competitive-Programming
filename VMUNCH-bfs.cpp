#include <bits/stdc++.h>
#include <string.h>
#include <queue>
#define maxn 100+10
using namespace std;

struct node {
	int v, next;
};

int d[100*maxn];
int s;
char a[maxn][maxn];
int head[100*maxn];
node graph[4*100*maxn];

void bfs() {
	queue<int> q;
	memset(d, 0, sizeof(d));
	d[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		int i = head[u];
		while (i!=0) {
			int v = graph[i].v;
			if (d[v]==0) {
				d[v] = d[u]+1;
				q.push(v);
			}
			i = graph[i].next;
		}
	}
	cout << d[1] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int dem, temp, r, c;
	cin >> r >> c;
	for (int i=1; i<=r; i++) {
		a[i][c+1] = '*';
		a[i][0] = '*';	
	}
	for (int j=1; j<=c; j++) {
		a[0][j] = '*';
		a[r+1][j] = '*';
	}
	
	dem = 0;
	memset(head, 0, sizeof(head));
	for (int i=1; i<=r; i++)
		for (int j=1; j<=c; j++) {
			cin >> a[i][j];
			if (a[i][j]=='C') s = (i-1)*c+j;
			if (a[i][j]=='.' || a[i][j]=='B' || a[i][j]=='C') {
				temp = (i-1)*c+j;
				if (a[i-1][j]=='.' || a[i-1][j]=='B' || a[i-1][j]=='C') {
					dem++;
					graph[dem].v = (i-1-1)*c+j;
					graph[dem].next = head[temp];
					head[temp] = dem;
					
					dem++;
					graph[dem].v = temp;
					graph[dem].next = head[(i-2)*c+j];
					head[(i-2)*c+j] = dem;
				}
				if (a[i][j-1]=='.' || a[i][j-1]=='B' || a[i][j-1]=='C') {
					dem++;
					graph[dem].v = (i-1)*c+j-1;
					graph[dem].next = head[temp];
					head[temp] = dem;
					
					dem++;
					graph[dem].v = temp;
					graph[dem].next = head[(i-1)*c+j-1];
					head[(i-1)*c+j-1] = dem;
				}
			}
		}
	bfs();
	return 0;
}
