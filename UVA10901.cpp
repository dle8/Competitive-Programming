#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxm 10000+10
#define mp make_pair
#define fi first
#define se second
#define oo 1000000000
using namespace std;

typedef pair<long, string> pls;
typedef pair<long, long> pll;

pls car[maxm];
long res[maxm];
pll leftq[maxm], rightq[maxm];

long min(long a, long b) {
	return (a<=b)?a:b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long lleft, lright, test_cases, n, t, m, arrive, rleft, rright, side, time, tmp, capacity;
	string bank;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> n >> t >> m;
		
		rleft = rright = 0;
		
		FOR(i, 1, m) {
			cin >> arrive >> bank;
			if (bank == "left") leftq[++rleft] = mp(arrive, i);
			else rightq[++rright] = mp(arrive, i);
		}
		
		leftq[rleft+1] = mp(oo, 0);
		rightq[rright+1] = mp(oo, 0);
		
		side = 1;
		time = 0;
		lleft = 1;
		lright = 1;
		while (true) {
			if (lleft>rleft && lright>rright) break;
			tmp = min(leftq[lleft].fi, rightq[lright].fi);
			capacity = 0;
			if (side==1) {
				side = 2;
				if (time<tmp) {
					time = tmp;
					if (tmp==rightq[lright].fi && tmp!=leftq[lleft].fi) {
						time+=t;
						continue;
					}
				}
				while (leftq[lleft].fi<=time && capacity<n) {
					res[leftq[lleft].se] = time+t;
					lleft++;
					capacity++;
				}
				time+=t;
			}
			else {
				side = 1;
				if (time<tmp) {
					time = tmp;
					if (tmp==leftq[lleft].fi && tmp!=leftq[lleft].fi) {
						time+=t;
						continue;
					}
				}
				while (rightq[lright].fi<=time && capacity<n) {
					res[rightq[lright].se] = time+t;
					lright++;
					capacity++;
				}
				time+=t;
			}
		}
		
		FOR(i, 1, m) cout << res[i] << "\n";
		
		if (current_test != test_cases) cout << "\n";
	}
	return 0;
}
