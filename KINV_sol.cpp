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
long n, k;
ll ft[maxn], d[maxk][maxn];;

bool smaller(const node&x, const node&y) {
	return (x.val<y.val);
}

void update(long i, ll val) {
	for (; i<=n; i+=(i&(-i))) ft[i]+=val;
}

ll getSum(long i) {
	ll sum = 0;
	for (; i>0; i-=(i&(-i))) sum = (sum+ft[i])%mod;
	return sum;
}

int main() {
	ll temp;
	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> a[i].val;
		a[i].pos = i;
	}
	
	sort(a+1, a+1+n, smaller);
	
	//d[length][i] luu so day ket thuc tai i co do dai la length
	//quy hoach dong
	FOR(length, 2, k) {
		memset(ft, 0, sizeof(ft));
		REP(i, n-1, 1) {
			temp = (length==2)? 1 : d[length-1][a[i+1].pos];
			update(a[i+1].pos, temp);
			d[length][a[i].pos] = getSum(a[i].pos);
			//cout << length << " " << d[length][a[i].pos] << " " << temp<< endl;
		}
	}
	
	ll res = 0;
	FOR(i, 1, n) res = (res+d[k][i])%mod;
	return cout << res, 0;
}
