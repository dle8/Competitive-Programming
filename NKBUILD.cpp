#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define oo 1e18
#define maxn 100+10
using namespace std;
 
struct node {
	long v;
	node* next;
};
 
long long d[maxn][maxn];
long n, m, k, trace[maxn][maxn], city[10];
set<long> visited;
set<long>::iterator iter;
 
void floyd() {
	FOR(u, 1, n)
	FOR(v, 1, n)
		trace[u][v] = v;//gia su duong di min giua moi cap dinh la duong di truc tiep
	
	FOR(med, 1, n)
	FOR(u, 1, n)
	FOR(v, 1, n) {
		if (d[u][v]>d[u][med] + d[med][v]) {
			d[u][v] = d[u][med] + d[med][v];
			trace[u][v] = trace[u][med];
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long mind, res, temp;
	long u, v, c, minVertice;
	node* p;
	cin >> n >> m >> k;
	FOR(i, 1, n)
	FOR(j, 1, n)
		if (i!=j) d[i][j] = oo;
		
	FOR(i, 1, k) cin >> city[i];
	
	FOR(i, 1, m) {
		cin >> u >> v >> c;
		d[u][v] = c;
		d[v][u] = c;
	}
	
	visited.clear();
	floyd();
	
	visited.insert(city[1]);
	res = 0;
	FOR(i, 2, k) {
		mind = oo;
		minVertice = 0;
		for (iter = visited.begin(); iter != visited.end(); iter++) {
			if (d[*iter][city[i]]<mind) {
				mind = d[*iter][city[i]];
				minVertice = *iter;
			}
		}
		res+=mind;
		temp = minVertice;
		do {
			temp = trace[temp][city[i]];
			visited.insert(temp);
		} while (temp!=city[i]);
	}
	
	cout << res;
	return 0;
} 
