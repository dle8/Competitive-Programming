#include <bits/stdc++.h>
#define maxn 100000+5
#define maxk 10+5
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mod 1000000000
using namespace std;
 
typedef long long ll;
 
struct node {
	ll val;
	long pos;
};
 
node a[maxn];
long fen[maxn], n, k, s[maxn];
ll ft[maxk][maxn];
 
bool smaller(const node&x, const node&y) {
	return (x.val<y.val);
}
 
void upfen(long i) {
	for(; i<=n; i+=(i&(-i))) fen[i]++;
}
 
long getFen(long i) {
	long sum = 0;
	for(; i>0; i-=(i&(-i))) sum+=fen[i];
	return sum;
}
 
void update(long length, long i, ll val) {
	for(; i<=n; i+=(i&(-i))) ft[length][i] = (ft[length][i]+val)%mod;
}
 
ll getSum(long length, long i) {
	ll sum = 0;
	for(; i>0; i-=(i&(-i))) sum = (sum+ft[length][i])%mod;
	return sum%mod;
}
 
int main() {
	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> a[i].val;
		a[i].pos = i;
	}
	
	sort(a+1, a+1+n, smaller);
	
	REP(i, n-1, 1) {
		upfen(a[i+1].pos);
		s[a[i].pos] = getFen(a[i].pos-1);
		if (s[a[i].pos]>0) update(2, a[i].pos, s[a[i].pos]);
	}
	
	FOR(length, 3, k) 
	REP(i, n-1, 1) 
		update(length, a[i].pos, getSum(length-1, a[i].pos-1));
	
	return cout << getSum(k, n), 0;
} 
