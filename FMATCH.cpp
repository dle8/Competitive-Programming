#include <bits/stdc++.h>
#define maxn 50000+10
#define FOR(i, l, r) for(int i=l; i<=r; i++)
using namespace std;

struct node {
	long val;
	node* next;
};

long trace[maxn], matchy[maxn], matchx[maxn];
long m, n, match; 
node* head[maxn];
bool flag, check[maxn];

long bfs(long u) {
	long x, y;
	queue<long> q;
	q.push(u);
//	memset(trace, 0, sizeof(trace));
	while (!q.empty()) {
		x = q.front();
		q.pop();
		
		node* p = head[x];
		while (p!=nullptr) {
			if (trace[p->val]<=0) {//neu nhu x chua dc di tham
				trace[p->val] = x;
				if (matchy[p->val]==0) return p->val;//neu nhu y chua dc ghep boi 1 bo ghep naof
				q.push(matchy[p->val]);
			}	
			p = p->next;
		}
		delete p;
	}

	return 0;
}

void enlarge(long y) {
	while (true) {
		long x = trace[y];
		
		node* p = head[x];
		while (p!=nullptr) {
			trace[p->val] = 0;
			p=p->next;
		}
		delete p;
		
		long next = matchx[x];
		matchx[x] = y;
		matchy[y] = x;
		y = next;
		if (y==0) break;		
	}
}

void maxiMatching() {
	long x, first, last, Stack[maxn];

	long top = 0;	
	FOR(i, 1, n) 
	if (check[i]) {
		top++;
		Stack[top] = i;
	}
	
	while (true) {
		long temp = top;
		for (int i=top; i>=1; i--) {
			long y = bfs(Stack[i]);
			if (y!=0) {
				enlarge(y);
				Stack[i] = Stack[first];
				first--;
				match++;
			}
		}
		if (temp==top) break;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v, cow;
	string s;
	node* p;
	memset(check, true, sizeof(check));
	memset(matchx, 0, sizeof(matchx));
	memset(matchy, 0, sizeof(matchy));
	memset(trace, 0, sizeof(trace));
	match = 0;
	cin >> n >> m >> cow;
	head[0] = nullptr;
	FOR(i, 1, cow) {
		cin >> u >> v;
		p = new node;
		p->val = v;
		p->next = head[u];
		head[u] = p;
		
		if (check[u] && matchy[v]==0) {
			match++;
			check[u] = false;
			matchy[v] = u;
			matchx[u] = v;
		}
	}
	
	maxiMatching();
	
	cout << match;
//	FOR(i, 1, m) if (matchx[i]!=0) cout << i << " " << matchx[i] << "\n";
	return 0;
}
