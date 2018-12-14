#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 1000+10
#define fi first
#define se second
#define oo 1000000000
using namespace std;

bool hasa[maxn], hasb[maxn], hasc[maxn];
string vitamins[maxn];
long price[maxn], n;

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long bmin, cmin, bcmin;
	memset(hasb, false, sizeof(hasb));
	memset(hasc, false, sizeof(hasc));
	memset(hasa, false, sizeof(hasa));
	bmin = 0; cmin = 0; bcmin = 0;
	price[0] = oo;
	cin >> n;
	FOR(i, 1, n) {
		cin >> price[i];
		cin >> vitamins[i];
		
		long lengthv = vitamins[i].length();
		FOR(j, 1, lengthv) {
			if (vitamins[i][j-1] == 'B') hasb[i] = true;
			if (vitamins[i][j-1] == 'C') hasc[i] = true;	
			if (vitamins[i][j-1] == 'A') hasa[i] = true;	
		}
		
		if (hasb[i] && price[i]<price[bmin]) bmin = i;
		
		if (hasc[i] && price[i]<price[cmin]) cmin = i;
		
		if (hasb[i] && hasc[i] && price[i]<price[bcmin]) bcmin = i;
	}
	
	long res = oo;
	FOR(i, 1, n) {
		if (!hasa[i]) continue;
		if (hasb[i] && hasc[i]) {
			res = min(res, price[i]);
			continue;	
		}
		if (hasb[i]) res = min(res, price[i]+price[cmin]);
		else if (hasc[i]) res = min(res, price[i]+price[bmin]);
		else res = min(res, price[i]+min(price[bmin]+price[cmin], price[bcmin]));
	}
	
	if (res==oo) return cout << -1, 0;
	return cout << res, 0;
}
