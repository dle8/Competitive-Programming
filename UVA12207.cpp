#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 1000+10
using namespace std;

long Stack[2*maxn];
map<long, long> pos;

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long p, top, bottom, x, ans, c, count, mmin, mmax;
	char tcase;
	
	count = 0;
	while (cin >> p) {
		cin >> c;
		if (p==0) break;
		
		mmin = min(c, p);
		top = mmin+1000; bottom = 1000+1;
		FOR(i, 1, mmin) {
			Stack[mmin+1000+1-i] = i;
			pos[i] = mmin+1000+1-i;
		}
		
		cout << "Case " << ++count << ":" << "\n";
		FOR(i, 1, c) {
			cin >> tcase;
			if (tcase=='N') {
				while (Stack[top]==0) top--;
				ans = Stack[top--];
				cout << ans << "\n";
				Stack[--bottom] = ans;
				pos[ans] = bottom;
			}
			else {
				cin >> x;
				Stack[++top] = x;
				Stack[pos[x]] = 0;
				pos[x] = top;
			}
		}
		
	}
	return 0;
}
