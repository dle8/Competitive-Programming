#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 500+10
using namespace std;

const int oo = 1e9;

int a[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int test, n;
	cin >> test;
	FOR(o, 1, test) {
		cin >> n;
		FOR(i, 1, n) cin >> a[i];
		
		int l = 1;
		int r = n;
		while (l<=r) {
			int mid = (l+r)/2;
			if (a[mid-1]>a[mid] || mid == 1) {
				cout << a[mid] << endl;
				break;
			}
			if (a[mid]<a[r]) r = mid-1;
			else l = mid+1;
		}
	}
	
	return 0;
}
