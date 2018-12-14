#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 20+2
using namespace std;

long k, n, kq[maxn], a[maxn][maxn], f[maxn][1<<maxn], way[maxn][1<<maxn];
set<long> Set[maxn];
set<long>::iterator iter;

long getBit(long j, long i) {
	return ((i>>(j-1))&1);
}

long setBit(long x, long j, long i) {
	if (x==0) return (i^(1<<(j-1)));
	return (i|(1<<(j-1)));
}

void update() {
	long temp = 0;
	FOR(i, 1, k) temp = setBit(1, kq[i], temp);
	Set[k].insert(temp);
}

void createNum(long i) {
	if (i>k) {
		update();
		return;
	}
	
	FOR(j, kq[i-1]+1, n-k+i) {
		kq[i] = j;
		createNum(i+1);	
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long tcount, temp;
	cin >> n;
	FOR(i, 1, n)
	FOR(j, 1, n) cin >> a[i][j];
	
	FOR(i, 1, n) {
		k = i;
		memset(kq, 0, sizeof(kq));
		createNum(1);
	}
	
	memset(f, 0, sizeof(f));
	tcount = 0;
	for(iter=Set[1].begin(); iter!=Set[1].end(); ++iter) {
		f[1][*iter] = a[1][++tcount];
		way[1][*iter] = 1;	
	}
	
	FOR(i, 2, n) //cho co con gai i
		for(iter=Set[i].begin(); iter!=Set[i].end(); ++iter) {
			FOR(x, 1, n) {
				if (getBit(x, *iter)==1) {
					temp = setBit(0, x, *iter);
					if (f[i][*iter]==f[i-1][temp]+a[i][x]) way[i][*iter] += way[i-1][temp];
					if (f[i][*iter]<f[i-1][temp]+a[i][x]) {
						f[i][*iter] = f[i-1][temp]+a[i][x];
						way[i][*iter] = way[i-1][temp];
					}
				}
			}
		}
	
	cout << f[n][(1<<n)-1] << " " << way[n][(1<<n)-1];
	return 0;
}
