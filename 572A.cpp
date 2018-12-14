#include <bits/stdc++.h>
#define maxn 100000+10
using namespace std;

long a[maxn], b[maxn], na, nb, k, m;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> na >> nb;
	cin >> k >> m;
	for (int i=1; i<=na; i++) cin >> a[i];
	for (int i=1; i<=nb; i++) cin >> b[i];
	if (a[k]<b[1+nb-m]) cout << "YES";
	else cout << "NO"; 
	return 0;
}
