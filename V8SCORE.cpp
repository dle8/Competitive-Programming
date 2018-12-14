#include <stdio.h>
#include <stdlib.h>
#include <ext/pb_ds/assoc_container.hpp>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 20+10
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
using namespace __gnu_pbds;

typedef tree<long, null_type, less<long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

typedef pair<long, long> node;

long s, k, n, a[maxn][maxn];
vector<node> f[maxn];
list<long> res;

void trace_back(long i, long j, long sum) {
	if (j==0) {
		printf("YES\n");
	//	cout << "YES" << "\n";
		for (auto it=res.begin(); it!=res.end(); it++) printf("%d ", *it);
		return;
	}
	
	res.push_front(a[i][j]);
	for (auto it=f[j-1].begin(); it!=f[j-1].end(); it++) {
		if (sum-a[i][j]==(*it).se) {
			trace_back((*it).fi, j-1, sum-a[i][j]);
			break;
		}
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//cin >> s >> k >> n;
	scanf("%d%d%d", &s, &k, &n);	
	FOR(i, 1, n)
	FOR(j, 1, k)
		scanf("%d", &a[i][j]); 
		//cin >> a[i][j];
	
	f[0].pb(mp(0, 0));
	FOR(i, 1, n) f[1].pb(mp(i, a[i][1]));
	FOR(j, 2, k) {
		for (auto it=f[j-1].begin(); it!=f[j-1].end(); it++) {
			FOR(i, 1, n)
				if ((*it).se+a[i][j]<=s && a[i][j]>=a[(*it).fi][j-1])
				f[j].pb(mp(i, (*it).se+a[i][j]));
		}
	}
	
	bool flag = false;
	for(auto it=f[k].begin(); it!=f[k].end(); it++) {
		if ((*it).se==s) {
			flag = true;
			trace_back((*it).fi, k, s);//thg cuoi cung la a[(*it).fi][k]
			break;
		}
	}
	
	if(!flag) return printf("NO"), 0;
	return 0;
}
