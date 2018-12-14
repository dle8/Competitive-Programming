#include <bits/stdc++.h>
#define maxn 10000+10
#define FOR(i, l, r) for(int i=l; i<=r; i++)
using namespace std;

struct node {
	long val;
	node* next;
};

long trace[maxn], matchy[maxn], matchx[maxn];
long m, n, match; 
node* head[maxn];
bool flag;

long bfs(long u) {
	long x, y;
	queue<long> q;
	q.push(u);
	memset(trace, 0, sizeof(trace));
	while (!q.empty()) {
		x = q.front();
		q.pop();
		
		node* p = head[x];
		while (p!=nullptr) {
			if (trace[p->val]==0) {//neu nhu x chua dc di tham
				trace[p->val] = x;
				if (matchy[p->val]==0) return p->val;//neu nhu y chua dc ghep boi 1 bo ghep naof
				q.push(matchy[p->val]);
			}	
			p = p->next;
		}
	}
	
	return 0;
}

void enlarge(long y) {
	while (true) {
		long x = trace[y];
		long next = matchx[x];
		matchx[x] = y;
		matchy[y] = x;
		y = next;
		if (y==0) break;		
	}
}

void maxiMatching() {
	long x, first, last, Stack[maxn];
	memset(matchx, 0, sizeof(matchx));
	memset(matchy, 0, sizeof(matchy));
	
	first = 0;
	last = 1;
	FOR(i, 1, m) {
		first++;
		Stack[first] = i;
	}
	
	while (true) {
		bool stop = true;
		for (int i=first; i>=last; i--) {
			long y = bfs(Stack[i]);
			if (y!=0) {
				stop = false;
				enlarge(y);
				Stack[i] = Stack[first];
				first--;
				match++;
			}
		}
		if (stop) break;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v;
	string s;
	node* p;
	cin >> m >> n;
	cin.ignore();
	while (getline(cin, s)) {
		if (s=="") break;
		int space = s.find(" ");
		u = stol(s.substr(0, space));
		v = stol(s.substr(space+1));
		
		p = new node;
		p->val = v;
		p->next = head[u];
		head[u] = p;
	}
	
	match = 0;
	maxiMatching();
	
	cout << match << "\n";
	FOR(i, 1, m) if (matchx[i]!=0) cout << i << " " << matchx[i] << "\n";
	return 0;
}
