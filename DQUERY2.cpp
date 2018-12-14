#include <bits/stdc++.h>
#define maxq 200000+10
#define maxn 30000+10
#define maxa 1000000+10
#define FORU(i, l, r) for (int i=l; i<=r; i++)
#define FORD(i, l, r) for (int i=l; i>=r; i--)
using namespace std;

struct que {
	long x, y, pos;
};

que query[maxq];
long res[maxq], ft[maxn], head[maxa], tnext[maxn], n, a[maxn];
bool check[maxa];

void update(long i) {
	for (; i<=n; i+=(i&(-i))) ft[i]++;
}

long getQuery(long i) {
	long sum = 0;
	for (; i>0; i-=(i&(-i))) sum+=ft[i];
	return sum;
}

bool compare(const que&a, const que&b) {
	return (a.x<b.x);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long q;
	cin >> n;
	FORU(i, 1, n) {
		cin >> a[i];
		if (!check[a[i]]) {
			check[a[i]] = true;
			update(i);
		}
	}
	
	//tao mang tnext
	FORD(i, n, 1) {
		tnext[i] = head[a[i]];
		head[a[i]] = i;
	}
	
	cin >> q;
	FORU(i, 1, q) {
		cin >> query[i].x >> query[i].y;
		query[i].pos = i;
	}
	
	sort(query+1, query+1+q, compare);
	//FORU(i, 1, q) cout << query[i].x << " " << query[i].y << " " << query[i].pos << "\n";	
	
	
	FORU(i, 1, q) {
		FORU(j, query[i-1].x, query[i].x-1) if (tnext[j]>=query[i].x) update(tnext[j]);
		res[query[i].pos] = getQuery(query[i].y) - getQuery(query[i].x-1);
	}
	
	FORU(i, 1, q) cout << res[i] << "\n";
	return 0;
}
