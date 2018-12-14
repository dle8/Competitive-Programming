#include <bits/stdc++.h>
#define maxn 100000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

long n, a[maxn], Stack[maxn];

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long tindex, top, p;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	
	tindex = 0;
	p = 1;
	top = 0;
	
	while (a[tindex]!=n) {
		tindex++;
		FOR(j, p+1, a[tindex]) {
			top++;
			Stack[top] = j;
		}
		p = max(p, a[tindex]);
		if (a[tindex]<Stack[top]) return cout << "YES", 0;
		else {
			if (Stack[top]==a[tindex]) top--;
		}
	}
	
	FOR(i, tindex+1, n-1) if (a[i]<a[i+1]) return cout << "YES", 0;
	
	return cout << "NO", 0;
}
