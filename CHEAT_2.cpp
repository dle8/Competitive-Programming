#include <bits/stdc++.h>
#define maxn 100000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

long a[maxn], vaolo[maxn], n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	vaolo[a[1]] = 1;
	FOR(i, 2, n) {
		vaolo[a[i]] = 1;
		if (a[i]<a[i-1]) {
			FOR(j, a[i]+1, a[i-1]-1) 
			if (vaolo[j]==0) return cout << "YES", 0;
		}
	}
	
	return cout << "NO", 0;
}
