#include <stdio.h>
#include <set>
#include <algorithm>
#define maxn 30000+10
using namespace std;

set<int> it[4*maxn];
int n;

void add(int cs, int u, int v, int i, int val) {
	it[cs].insert(val);
	if (u==i && v==i) return;
	int mid = (u+v)/2;
	if (i<=mid) add(2*cs, u, mid, i, val);
	else add(2*cs+1, mid+1, v, i, val);
}

set<int> count(int cs, int u, int v, int l, int r) {
	if (u==l && v==r) return it[cs];
	int mid = (u+v)/2;
	if (r<=mid) return count(2*cs, u, mid, l, r);
	if (l>=mid+1) return count(2*cs+1, mid+1, v, l, r);
	set<int> p1 = count(2*cs, u, mid, l, mid);
	set<int> p2 = count(2*cs+1, mid+1, v, mid+1, r);
	
	set<int> whole;
	merge(p1.begin(), p1.end(), p2.begin(), p2.end(), inserter(whole, whole.end()));
	
	return whole;
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q, l, r, elem;
	scanf("%d", &n);
//	cin >> n;
	for (int i=1; i<=n; i++) {
		scanf("%d", &elem);
		//cin >> elem;
		add(1, 1, n, i, elem);
	}
	scanf("%d", &q);
//	cin >> q;
	for (int i=1; i<=q; i++) {
		//cin >> l >> r;
		scanf("%d %d", &l, &r);
		printf("%d\n", count(1, 1, n, l, r).size());
		//cout << count(1, 1, n, l, r).size() << endl;
	}
	return 0;
}
