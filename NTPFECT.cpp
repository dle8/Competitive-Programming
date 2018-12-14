#include <bits/stdc++.h>
#define maxn 1000+10
using namespace std;

struct node {
	int v, next;
};

node graph[2*maxn];
int head[maxn], kq[maxn][3], check[maxn];

int min(int a, int b){
	if (a<=b) return a;
	else return b;
}

void dfs(int u) {
	int v;
	bool flag1,isLeaf,flag0;
	isLeaf=true;
	int i = head[u];
	while (i!=0) {
		v = graph[i].v;
		if (check[v]==0) {
			isLeaf=false;
			check[v] = u;
			dfs(v);
		}
		i = graph[i].next;
	}
	
	if (isLeaf){
		kq[u][2]=1;
		kq[u][1]=1000000000;
		kq[u][0]=0;
		return;	
	}
	
	kq[u][2]=1;
	flag0=false;
	flag1=false;
	int tmin=1000000000;
	i = head[u];
	while (i!=0) {
		v = graph[i].v;
		if (check[v]==u) {
			if (kq[v][1]==1000000000) flag0=true;
			else kq[u][0]+=kq[v][1];
			if (kq[v][2]<=kq[v][1]){
				flag1=true;
				kq[u][1]+=kq[v][2];
			}
			else
			{
				tmin=min(tmin,kq[v][2]-kq[v][1]);
				kq[u][1]+=kq[v][1];	
			}
			kq[u][2]+=min(kq[v][0],min(kq[v][1],kq[v][2]));
		}
		i = graph[i].next;
	}
	if (flag0) kq[u][0]=1000000000;
	if (!flag1) kq[u][1]+=tmin;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, u, v, res, dem;
	while (true) {
		cin >> n;
		if (n==0) break;
		memset(head, 0, sizeof(head));
		memset(check, 0, sizeof(check));
		for (int i=1;i<=n;i++)
		for (int j=0;j<=2;j++) kq[i][j]=0;
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
		check[1]=-1;
		dfs(1);
		cout << min(kq[1][1], kq[1][2]) << "\n"; 		
	}
	return 0;
}
