#include <bits/stdc++.h>
#define maxn 100+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define mp make_pair
#define fi first
#define se second
#define oo 1e15+10
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll m, n, houses, h[maxn][maxn], first, last, minHouse, maxHouse; 
char c[maxn][maxn];
bool inQueue[maxn][maxn];
pll s, q[110*maxn];

void add(ll x, ll y, ll minv, ll maxv) {
	if (x>0 && y>0 && x<=m && y<=n && !inQueue[x][y] && (minv<=h[x][y]) && (h[x][y]<=maxv)) {
		inQueue[x][y] = true;
		q[++last] = mp(x, y);
	}
}

bool bfs(ll minv, ll maxv) {
	ll count;
	FOR(i, 1, m) memset(inQueue[i], false, sizeof(inQueue[i]));
	
	first = 1;
	last = 0;
	
	add(s.fi, s.se, minv, maxv);
	
	count = 0;
	while (first<=last) {
		pll u = q[first++];
		
		if (c[u.fi][u.se]=='K')  count++;
		if (count==houses) return true;
		
		add(u.fi-1, u.se-1, minv, maxv);
		add(u.fi, u.se-1, minv, maxv);
		add(u.fi+1, u.se-1, minv, maxv);
		add(u.fi-1, u.se, minv, maxv);
		add(u.fi+1, u.se, minv, maxv);
		add(u.fi-1, u.se+1, minv, maxv);
		add(u.fi, u.se+1, minv, maxv);
		add(u.fi+1, u.se+1, minv, maxv);
	}
	
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll dau, cuoi, dd, cc, res;
	cin >> m >> n;
	houses = 0;
	FOR(i, 1, m)
	FOR(j, 1, n) {
		cin >> c[i][j];
		if (c[i][j]=='K') houses++;
		if (c[i][j]=='P') s = mp(i, j);	
	}
	
	minHouse = oo;
	maxHouse = -oo;
	FOR(i, 1, m)
	FOR(j, 1, n) {
		cin >> h[i][j];
		if (c[i][j]=='K' || c[i][j]=='P') {
			if (minHouse>h[i][j]) minHouse = h[i][j];
			if (maxHouse<h[i][j]) maxHouse = h[i][j];
		}
	}
	
	dau = 0;
	cuoi = minHouse;
	res = oo;
	//voi moi thg lowerbound tim diff nho nhat -> neu tim dc thi nang lowebound, else giam lowerbound xuong
	while (dau<=cuoi) {
		ll lowerBound = (dau+cuoi)/2;
		bool flag = false;
		
		dd = 0;
		cc = 1e9L;
		
		while (dd<=cc) {
			ll mid = (dd+cc)/2;
			if ((lowerBound+mid>=maxHouse) && bfs(lowerBound, lowerBound+mid)) {
				flag = true;
				cc = mid-1;
			}
			else dd = mid+1;
		}
		
		if (flag) {
			if (res>dd) res = dd;
			dau = lowerBound+1;
		}
		else cuoi = lowerBound-1;
	}
	
	return cout << res, 0;
}
