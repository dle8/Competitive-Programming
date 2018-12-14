#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 200000+10
using namespace std;

queue<long> q;
long long capacity, n, t[maxn], d[maxn], res[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long tmp;
	long long r;
	cin >> n >> capacity;
	FOR(i, 1, n) cin >> t[i] >> d[i];
	
	res[1] = r = t[1]+d[1];
	FOR(i, 2, n) {
		if (t[i]<r && q.size()==capacity) res[i] = -1;
		else {
			q.push(i);
			if (t[i]>=r) {
				do {
					tmp = q.front();
					q.pop();
					r = max(r, t[tmp]);
					r+=d[tmp];
					res[tmp] = r;
				} while (r<=t[i] && !q.empty());
			}
		}
	}
	
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		r+=d[tmp];
		res[tmp] = r;
	}
	
	FOR(i, 1, n) cout << res[i] << " ";
	return 0;
}


