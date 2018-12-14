#include <bits/stdc++.h>
#define maxn 5000+10
#define maxm 10000+10
#define maxc 1000000000
using namespace std;

long c[maxn][maxn], f[maxn][maxn], s[maxn], t[maxn], roads;
bool check[maxn];

long min(long a, long b) {
	if (a<b) return a;
	else return b;
}

void dfs(long u) {
	long v;
	long i = head[u];
	while (i!=0) {
		v = graph[i].v;
		if (trace[v]==0 && (c[u][v]-f[u][v]>0)) {
			trace[v] = u;
			dfs(v);
		}
		i = graph[i].next;
	}
}

void update(long u, long v, long flow) {
	f[u][v]+=flow;
	f[v][u]-=flow;
}

void bfs(long u) {
	
}

void findPath() {
	long temp, flow;
	while (true) {
		memset(trace, 0, sizeof(trace));
		dfs(1);
		if (trace[n]==0) break;
		
		temp = n;
		flow = maxc;
		while (temp!=1) {
			flow = min(flow, c[trace[temp]][temp]-f[trace[temp]][temp]);
			temp = trace[temp];
		}
		
		temp = n;
		while (temp!=1) {
			update(trace[temp], temp, flow);
			temp = trace[temp];
		}
	}
	
	memset(check, true, sizeof(check));
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long count;
	string[4] input;
	cin >> n;
	roads = 0;
	while (getline(cin, s)) {
		istringstream buf(s);
		istream_iterator<string> beg(buf), end;
		vector<string> tokens(beg, end);
		
		count = 0;
		for (auto& token: tokens) {
			count++;
			input[count] = token;
		}
		
		u = stol(input[1]);
		v = stol(input[2]);
		c = stol(input[3]);
		
		roads++;
		s[roads] = u;
		t[roads] = v;
		c[u][v] = c;
		c[v][u] = 0;
	}
	
	return 0;
}
