#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define oo 1e15
#define maxn 100+10
using namespace std;
 
long long d[maxn][maxn];
long n, trace[maxn][maxn], city[10];
//set<long> visited;
//set<long>::iterator iter;

long long min(long long a, long long b) {
	if (a<=b) return a;
	else return b;
}
 
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
	cin >> n;
	FOR(i, 1, n)
	FOR(j, 1, n)
		if (i!=j) d[i][j] = oo;
		
	FOR(i, 1, 4) cin >> city[i];
	
	while (cin >> u) {
		cin >> v >> c;
		d[u][v] = c;
		d[v][u] = c;
	}
	
	floyd();

	res = oo;
	FOR(i, 1, n)
	FOR(j, 1, n) {
		res = min(res, d[i][city[1]]+d[i][city[2]]+d[i][j]+d[j][city[3]]+d[j][city[4]]);
	}
	
	cout << res;
	return 0;
} 
