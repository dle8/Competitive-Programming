/*
Author: Dung Tuan Le
University of Rochester
*/
 
#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define oo 1000000000
 
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
 
#define maxn 1000+10
 
struct node {
	long v;
	node* next;
};
 
long team[maxn];
long n, tindex, topo[maxn];
node* head[maxn];
bool visited[maxn];

void dfs(long u) {
	long v, mmin = oo, tmp;
	topo[++tindex] = u;
	
	node* p = head[u];
	visited[u] = true;
	while (p != nullptr) {
		v = p->v;
		if (!visited[v]) {
			team[v]--;
			if (mmin > team[v]) {
				mmin = team[v];
				tmp = v;
			}
		}
		p = p->next;
	}
	
	if (mmin != oo) dfs(tmp);
} 
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	node* p;
	char input;
	long u, v, s;
	
	cin >> n;
	
	memset(team, 0, sizeof(team));
	
	FOR(i, 1, n) 
	FOR(j, 1, n) {
		cin >> input;
		if (input == '1') {
			p = new node;
			p->v = j;
			p->next = head[i];
			head[i] = p;
			
			team[j]++;
		}
	}
	
	memset(visited, false, sizeof(visited));
	tindex = 0;
	
	FOR(i, 1, n) 
		if (team[i] == 0) s = i;

	dfs(s);
	
	if (tindex < n) return cout << -1, 0;
	
	FOR(i, 1, tindex) cout << topo[i] << " ";
	
	return 0;
}
