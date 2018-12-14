#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 1000000+10
#define mp make_pair
#define fi first
#define se second
using namespace std;

typedef pair<long, long> pll;

struct pts {
	long val;
	bool left = false;
	bool right = false;
};

pts point[2*maxn];
pll res[maxn];
long n, k;

bool cmp(const pts&a, const pts&b) {
	return ((a.val<b.val) || (a.val==b.val && a.left && b.right));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long l, r;
	cin >> n >> k;
	
	FOR(i, 1, n) {
		cin >> l >> r;
		point[2*i-1].val = l;
		point[2*i-1].left = true;

		point[2*i].val = r;
		point[2*i].right = true;
	}
	
	sort(point+1, point+1+2*n, cmp);
	
	long count = 0, seg = 0;
	FOR(i, 1, 2*n) {
		if (point[i].left) count++;
		if (count==k) {
			if (point[i].left) res[++seg].fi = point[i].val;	
			else res[seg].se = point[i].val;
		}
		if (point[i].right) count--;
	}
	
	cout << seg << "\n";
	FOR(i, 1, seg) cout << res[i].fi << " " << res[i].se << "\n";
	return 0;
}
