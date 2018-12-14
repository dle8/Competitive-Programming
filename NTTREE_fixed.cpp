#include <bits/stdc++.h>
#include <string.h>
#define maxn 10000+10
using namespace std;

struct node {
	long long v, c, next;
};

node tree[2*maxn];
int n;
bool check[maxn];
int head[maxn], socon[maxn], u[maxn], v[maxn];
long long totalWeight;
long long w[maxn];

int min(int a, int b) {
	if (a<=b) return a;
	else return b;
}

void tinhSoCon(int u) {
	int v;
	int i = head[u];
	check[u] = false;
	while (i!=0) {
		v = tree[i].v;
		if (check[v]) {
			socon[u]++;
			tinhSoCon(v);
		}
		i = tree[i].next;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i=1; i<=(n-1); i++) {
		cin >> u[i] >> v[i] >> w[i];
		u[i]++;
		v[i]++;
		
		tree[2*i].v = v[i];
		tree[2*i].c = w[i];
		tree[2*i].next = head[u[i]];
		head[u[i]] = 2*i;
		
		tree[2*i+1].v = u[i];
		tree[2*i+1].c = w[i];
		tree[2*i+1].next = head[v[i]];
		head[v[i]] = 2*i+1;	
	}
	
	memset(check, true, sizeof(check));
	for (int i=1; i<=n; i++) socon[i] = 1;
	tinhSoCon(1);
	totalWeight = 0;
	for (int i=1; i<=(n-1); i++) {
		totalWeight+=(w[i]*min(socon[u[i]], socon[v[i]])*(n-min(socon[u[i]], socon[v[i]])));
	}
	cout << totalWeight;
	return 0;
}
