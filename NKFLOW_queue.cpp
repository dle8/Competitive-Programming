#include <iostream>
#include <string.h>
#include <math.h>

//lam theo cach duong tang luong(augment path)
using namespace std;

int n, m, s, t, maxFlowOfOneWay;
int f[1000+10][1000+10],c[1000+10][1000+10];
int trace[1000+10];

int max(int a, int b) {
	if (a>=b) return a;
	else return b;
}

int min(int a, int b) {
	if (a<=b) return a;
	else return b;
}

void bfs(int u){
	int queue[2*1000+10];
	int first=1;
	int last=1;
	queue[1]=u;
	while (first<=last)
	{
		u=queue[first];
		first++;
		for (int v=1;v<=n;v++)
		if (trace[v] == 0 && (c[u][v]-f[u][v])>0) {//ong nuoc chua day
			trace[v] = u;
			last++;
			queue[last]=v;
			if (v==t) return;
		}
	}
}

void update(int u, int v, int flow) {//sua do thong qua tu u den v bang c
	f[u][v]+=flow;
	f[v][u]-=flow;
}

int main() {
	int u, v, value, dinhao, totalMax;
	int diachi;
	cin >> n >> m >> s >> t;
	for (int i=1; i<=m; i++) {
		cin >> u >> v >> value;
		c[u][v]=value;
		c[v][u]=0;		
	}
	
	//dfs tu s den t. tren duong truy vet gan lai cac canh la -c. neu truy vet den s thi lai dfs cho den khi f max.
	while (1!=0) {
		memset(trace, 0, sizeof(trace));
		maxFlowOfOneWay = 1000000000;
		bfs(s);
		if (trace[t]==0) break;
		
		dinhao = t;
		while (dinhao!=s) {
			maxFlowOfOneWay=min(maxFlowOfOneWay,c[trace[dinhao]][dinhao]-f[trace[dinhao]][dinhao]);
			dinhao = trace[dinhao];
		}
		
		dinhao = t;
		while (dinhao!=s) {
			update(trace[dinhao], dinhao, maxFlowOfOneWay);
			dinhao = trace[dinhao];
		}
	}
	
	totalMax = 0;
	for (int i=1;i<=n;i++)
	if (c[s][i]>0) totalMax+=f[s][i];
	
	cout << totalMax;
	return 0;
}
