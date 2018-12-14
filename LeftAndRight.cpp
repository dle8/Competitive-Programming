/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<ll, ll> pllll;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

#define maxn 200000+10

struct node {
	long v;
	node* next;	
};

node* head[maxn];
long tcount[maxn], res[maxn];
pll house[maxn];
bool check[maxn];

struct cmp {
	bool operator()(const pll&x, const pll&y) {
		return (x.se > y.se || (x.se == y.se && x.fi > y.fi));
	}
};

int main() {
	fio;
	
	long n;
	string directions;
	cin >> n;
	cin >> directions;
	
	FOR(i, 1, n) {
		house[i].fi = i;
		house[i].se = 0;
	}
	
	FOR(i, 0, n-2) {
		node* p = new node;
		if (directions[i] == 'R') {
			p->v = i+2;
			p->next = head[i+1];
			head[i+1] = p;
			
			house[i+2].se++;			
		}
		else {
			p->v = i+1;
			p->next = head[i+2];
			head[i+2] = p;
			
			house[i+1].se++;
		}
	}
	
	priority_queue<pll, vector<pll>, cmp> pq;
	
	FOR(i, 1, n) pq.push(house[i]);
	
	long order = 0;
	memset(check, false, sizeof(check));
	while (!pq.empty()) {
		pll u = pq.top();
		pq.pop();
		
		if (check[u.fi]) continue;
		check[u.fi] = true;
		res[u.fi] = ++order;
		
		node* p = head[u.fi];
		while (p != nullptr) {
			long v = p->v;
			house[v].se--;
			pq.push(house[v]);
			p = p->next;
		}
	}
	
	FOR(i, 1, n) cout << res[i] << "\n";
	return 0;
}
