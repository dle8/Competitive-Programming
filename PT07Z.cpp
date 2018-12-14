#include <bits/stdc++.h>
#define maxn 10000+10
#define maxc 1000000000
using namespace std;

struct node{
	long v, next;
};

node graph[2*maxn];
long n, farthestP, longestLength, head[maxn];
bool check[maxn];

void dfs(long u, long tlength) {
	bool isLeaf = true;
	long v;
	long i = head[u];
	check[u] = false;
	while (i!=0) {
		v = graph[i].v;
		if (check[v]) {
			isLeaf = false;
			dfs(v, tlength+1);	
		}
		i = graph[i].next;
	} 
	if (isLeaf && tlength>longestLength) {
		farthestP = u;
		longestLength = tlength;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v;
	cin >> n;
	memset(head, 0, sizeof(head));
	for (int i=1; i<n; i++) {
		cin >> u >> v;
		graph[2*i].v = v;
		graph[2*i].next = head[u];
		head[u] = 2*i;
		
		graph[2*i+1].v = u;
		graph[2*i+1].next = head[v];
		head[v] = 2*i+1;
	}
	memset(check, true, sizeof(check));
	longestLength = 0;
	dfs(1, 0);
	longestLength = 0;
	memset(check, true, sizeof(check));
	dfs(farthestP, 0);
	cout << longestLength;
	return 0;
}
