#include <bits/stdc++.h>
#include <string>
#define maxm 100000+10
#define maxn 10000+10
using namespace std;

struct node {
	int v, next;
};

class stk {
	public: 
		int elem[maxn];
		int first, top, val;
	
	void init() {
		first = 1;
		top = 0;
		val = 0;
	}
	
	bool empty() {
		return (first>top);
	}
	
	int peek() {
		return (elem[top]);
	}
	
	void add(int x) {
		top++;
		elem[top] = x;
	}
	
	void poll() {
		top--;
	}
	
	void setEmpty() {
		top = 0;
		val = 0;
	}
};

int n, source, t;
node graph[maxm];
bool check[maxn], canComeToT[maxn];
int head[maxn], danhdau[maxn];
stk s;

void dfs(int u) {
	int v;
	int i = head[u];
	
	while (i!=0) {
		v = graph[i].v;
		if (check[v]) {
			if (v==t) {
				danhdau[t]++;
				s.val++;
				canComeToT[u] = true;
				continue;
			}
			s.add(v);
			check[v] = false;
			dfs(v);
			canComeToT[u] = canComeToT[u] || canComeToT[v];
			if (!s.empty() ) {
				if (canComeToT[s.peek()]) danhdau[s.peek()]+=s.val;
				s.poll();
			}
			check[v] = true;
		}
		i = graph[i].next;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, u, v, result;
	cin >> n >> m >> source>> t;
	for (int i=1; i<=m; i++) {
		cin >> u >> v;
		graph[i].v = v;
		graph[i].next = head[u];
		head[u] = i;
	}
	memset(check, true, sizeof(check));
	memset(canComeToT, false, sizeof(canComeToT));
	memset(danhdau, 0, sizeof(danhdau));
	stk s;
	s.init();
	dfs(source);
	result = 0;
	for (int i=1; i<=n; i++) 
		if (danhdau[i]==danhdau[t] && i!=t) result++;
	cout << result;
	return 0;
}
