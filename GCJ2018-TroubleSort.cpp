#include <bits/stdc++.h>
#define maxn 100000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define oo 2e9
using namespace std;

long e[maxn], o[maxn], a[maxn];

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

int main() {
	long res, ttest, n, odd, even, num;
	scanf("%ld", &ttest);
	FOR(i, 1, ttest) {
		scanf("%ld", &n);
		odd = 0;
		even = 0;
		FOR(j, 1, n) {
			scanf("%ld", &num);
			if (j%2==0) {
				even++;
				e[even] = num;
			}
			else {
				odd++;
				o[odd] = num;
			}
		}
		sort(e+1, e+1+even);
		sort(o+1, o+1+odd);
		
		res = 0;
		FOR(j, 1, odd) a[j*2-1] = o[j];
		FOR(j, 1, even) a[j*2] = e[j];
		FOR(j, 1, n-1) {
			if (a[j]>a[j+1]) {
				res = j;
				break;
			}
		}
		printf("Case #%d: ", i);
		if (res==0) printf("OK\n");
		else printf("%ld\n", res-1);
	}
	return 0;
}
