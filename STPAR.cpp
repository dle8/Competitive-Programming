#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 1000+10
#define oo 1000000000
using namespace std;

long n, a[maxn], Stack[maxn];
bool flag;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (cin >> n) {
		if (n==0) break;
		FOR(i, 1, n) cin >> a[i];
		
		long min = 1, top = 0;
		Stack[top] = oo;
		bool flag = false;
		FOR(i, 1, n) {
			if (min==a[i]) min++;
			else {
				while (min==Stack[top]) {//pop ra khoi stack
					min++;
					top--;
				}
				if (a[i]>Stack[top]) flag = true;
				if (flag) break;
				Stack[++top] = a[i];
			}
		}
		
		if (flag) cout << "no" << "\n";
		else cout << "yes" << "\n";
	}
	return 0;
}
