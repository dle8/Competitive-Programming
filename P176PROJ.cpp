#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 200000+10
using namespace std;
using namespace __gnu_pbds;

typedef tree<long, null_type, less<long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

long n, m, a[maxn], l[maxn], r[maxn];

long getPrimePower(long n) {
	if (n==1 || n==2 || n==3) return 1;
	long sum = 0;
	bool isPrime = true;
	FOR(i, 2, sqrt(n)) {
		if (n%i==0) {
			isPrime = true;
			while (n%i==0) {
				n/=i;
				sum++;
			}
		}
	}

	return sum;	
}

void update(long i, long val) {
	for(; i<=n; i+=(i&(-i))) ft[i]+=val;
}

long getSum(long i) {
	long sum = 0;
	for(; i>0; i-=(i&(-i))) sum+=ft[i];
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	cin >> m;
	FOR(i, 1, m) cin >> l[i] >> r[i];
	
	FOR(i, 1, n) update(i, getPrimePower(a[i]));
	return 0;
}
