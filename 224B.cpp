#include <bits/stdc++.h>
#define FORU(i, l, r) for (int i=l; i<=r; i++)
#define FORD(i, l, r) for (int i=l; i>=r; i--)
#define maxn 100000+10
using namespace std;

long n, k;
long a[maxn], tnext[maxn], head[maxn];
bool check[maxn];

int main() {
	ios_base::sync_with_stdio(0);
	long l, r;
	cin >> n >> k;
	FORU(i, 1, n) cin >> a[i];
	FORD(i, n, 1) {
		tnext[i] = head[a[i]];
		head[a[i]] = i;
	}
	
	
	memset(check, true, sizeof(check));
	long count = 0;
	FORU(i, 1, n) {
		if (check[a[i]]) {
			check[a[i]] = false;
			count++;
		}
		if (count==k) {
			r = i;
			break;
		}
	}
	if (count<k) return cout<<-1 << " " << -1, 0;
	l = 1;
	FORU(i, 1, n) {
		if (tnext[i]<=r && tnext[i]!=0) l++;
		else break;
	}
	
	cout << l << " " << r;
	return 0;
}
