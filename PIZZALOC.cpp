#include <iostream>
#include <cmath>
#define FOR(i, l, r) for(int i=l; i<=r; i++)
#define maxc 1000000000
#define maxn 100+10
#define maxm 20+10
using namespace std;

long k, r, m, n, res, kq[maxm], rx[maxm], ry[maxm], hx[maxn], hy[maxn], s[maxn], mask[maxn], restaurants;

inline double getDist(long x, long y, long xx, long yy) {
	return sqrt(pow(x-xx, 2)+pow(y-yy, 2));
}

void update() {
	long ppl = 0;
	FOR(i, 1, n)
		if (restaurants&mask[i]) ppl+=s[i];
	if (res<ppl) res = ppl;
}

void recursive(long i) {
	if (i>k) {
		update();
		return;
	}
	
	FOR(j, kq[i-1]+1, m-k+i) {
		kq[i] = j;
		restaurants += (1<<(j-1));//danh dau la chon nha hang j
		recursive(i+1);
		restaurants -= (1<<(j-1));
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k >> r;
	cin >> m;
	
	FOR(i, 1, m) cin >> rx[i] >> ry[i];
	cin >> n;
	FOR(i, 1, n) cin >> hx[i] >> hy[i] >> s[i];
	
	FOR(i, 1, n) 
	FOR(j, 1, m)
	if (getDist(hx[i], hy[i], rx[j], ry[j])<=r) mask[i]+=(1<<(j-1));
	
	res = -maxc;
	restaurants = 0;
	recursive(1);
	cout << res;
	
	return 0;
}
