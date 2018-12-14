#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 10000+10
#define oo 1000000000000000000
using namespace std;

typedef long long ll;

struct node {
	ll height, price;
};

node building[maxn];
ll ft[maxn];
long n;

bool cmp(const node&x, const node&y) {
	return (x.height<y.height);
}

void update(long i, long val) {
	for(; i<=n; i+=(i&(-i))) ft[i]+=val;
}

ll getSum(long i) {
	ll sum = 0;
	for(; i>0; i-=(i&(-i))) sum+=ft[i];
	return sum;	
}

long bs(long dau, long cuoi, long key){//tim thg dau tien <key trong day
	long d = dau;
	long c = cuoi;
	
	while (d<=c) {
		long mid = (d+c)/2;
		if (building[mid].height>=key) c = mid-1;
		else d = mid+1; 
	}
	
	return c;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll totalCost, res;
	long test, maxHeight; 
	cin >> test;
	FOR(o, 1, test) {
		totalCost = 0;
		maxHeight = 0;
		memset(ft, 0, sizeof(ft));
		cin >> n;
		FOR(i, 1, n) {
			cin >> building[i].height;
			if (building[i].height>maxHeight) maxHeight = building[i].height;
		}
		FOR(i, 1, n) {
			cin >> building[i].price;
			totalCost+=(building[i].price*building[i].height);	
		}
		
		sort(building+1, building+1+n, cmp);
		
		FOR(i, 1, n) update(i, building[i].price);
		
		res = oo;
		if (totalCost<res) res = totalCost;
		FOR(k, 1, maxHeight) {
			//chat nhi phan tim vi tri thg dau tien co height < k trong day
			long ti = bs(1, n, k);
			totalCost+=getSum(ti);
			totalCost-=(getSum(n)-getSum(ti));
			
			if (totalCost<res) res = totalCost;
		}
		
		cout << res << "\n";
	}
	return 0;
}
