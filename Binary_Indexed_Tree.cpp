#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
using namespace std;

void update(long i, long val) {
	for(; i<=n; i+=(i&(-i))) ft[i]+=val;
}

long getSum(long i) {
	long sum = 0;
	for (; i>0; i-=(i&(-i))) sum+=ft[i];
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	return 0;
}
