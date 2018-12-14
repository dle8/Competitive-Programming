#include <bits/stdc++.h>
#define maxn 100000+10
#define FORU(i, l, r) for(int i=l; i<=r; i++)
#define FORD(i, l, r) for(int i=l; i>=r; i--)
using namespace std;

long n, k, a[maxn];
bool check[maxn];

long bs(long key) {
	long d = 1;
	long c = n;
	while (d<=c) {
		long mid = (d+c)/2;
		if (a[mid]>=key) c = mid-1;
		else d = mid+1;
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long res;
	cin >> n >> k;
	FORU(i, 1, n) cin >> a[i];
	
	sort(a+1, a+1+n);
	res = 0;
	memset(check, true, sizeof(check));
	long neo =  n+1;
	FORD(i, n, 1) {
		long index = bs(a[i]+k);
		if (index==n+1) res+=a[i];
		else {
			long j = neo-1;
			while (a[i]+k>a[j] && j>i) j--;
			if (j==i) {
				res+=a[i];
				neo = j+1;
			}
			else neo = j;
		}
	}
	cout << res;
	return 0;
}
