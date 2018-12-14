#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 10000+10
#define oo 1000000000
using namespace std;
using namespace __gnu_pbds;

typedef tree<long, null_type, less<long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

long a[2*maxn];

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long test, l, r, city, n, p, maxcity;
	
	freopen("input3.in", "r", stdin);
	freopen("output.out", "w", stdout);
	cin >> test;
	FOR(o, 1, test) {
		cin >> n;
		memset(a, 0, sizeof(a));
		maxcity = -oo;
		FOR(i, 1, n) {
			cin >> l >> r;
			a[l]+=1;
			a[r+1]-=1;
//			maxcity = max(maxcity, l);
			maxcity = max(maxcity, r);
		}
		
		FOR(i, 1, maxcity) a[i]+=a[i-1];
		
		cout << "Case #" << o << ": ";
		cin >> p;
		FOR(i, 1, p) {
			cin >> city;
			cout << a[city] << " ";
		}
		cout << "\n";
	}
	return 0;
}
