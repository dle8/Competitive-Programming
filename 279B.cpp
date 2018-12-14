#include <bits/stdc++.h>
#define FORU(i, l, r) for (int i=l; i<=r; i++)
#define FORD(i, l, r) for (int i=l; i>=r; i--)
#define oo 1000000000
#define maxn 100000+10
using namespace std;

long a[maxn], ttime[maxn], l[maxn];
long n, t;

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	bool stop = false;
	long tt, neo;
	cin >> n >> t;
	FORU(i, 1, n) cin >> a[i];
	
	ttime[n+1] = t;
	neo = n;
	
	FORD(i, n, 1) {
		tt = ttime[i+1]+a[i+1];//ttime[i+1] la tgian con sot lai
		FORD(j, neo, 1) {
			if (tt-a[j]>=0) {
				tt-=a[j];
				l[i] = j;
			}
			else {
				l[i] = j+1;
				break;
			}
		}
		neo = l[i]-1;
		ttime[i] = tt;
	}
	
	long maxBook = -oo;
	FORU(i, 1, n) maxBook = max(maxBook, i-l[i]+1);
	cout << maxBook;
	return 0;
}
