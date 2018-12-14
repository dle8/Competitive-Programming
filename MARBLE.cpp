#include <bits/stdc++.h>
#define maxn 50000+10
using namespace std;

int n;
int itop[maxn], ibottom[maxn], ileft[maxn], iright[maxn];

int min(int a, int b) {
	if (a<=b) return a;
	else return b;
}

int max(int a, int b) {
	if (a>=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int k, q, d, u, v, res;
	string tcase;
	cin >> n >> k >> q;
	for (int i=1; i<=n; i++) {
		itop[i] = n+1;
		ibottom[i] = 0;
		ileft[i] = n+1;
		iright[i] = 0; 
	}
	for (int i=1;  i<=k ; i++) {
		cin >> u >> v;//dong u, cot v
		itop[v] = min(itop[v], u);
		ibottom[v] = max(ibottom[v], u);
		ileft[u] = min(ileft[u], v);
		iright[u] = max(iright[u], v);
	}

	for (int i=1; i<=q; i++) {
		cin >> tcase;
		cin >> d >> u >> v;
		res = 0;
		if (tcase == "L") {
			for (int i=1; i<=d; i++) {
				res += (ileft[u]-1);//ileft[i]>=1 voi 1<=i<=n
				itop[v] = max(1, itop[v]-1);

				itop[ileft[u]] = min(itop[ileft[u]], ileft[u]);
				ibottom[ileft[u]] = max(ibottom[ileft[u]], ileft[u]);
			}
			cout << res << "\n";
		}
		if (tcase == "R") {
			for (int i=1; i<=d; i++) {
				res += (n-iright[u]);
				iright[u] = min(n, iright[u]+1);
				itop[iright[u]] = min(itop[iright[u]], iright[u]);
				ibottom[iright[u]] = max(ibottom[iright[u]], iright[u]);
			}
			cout << res << "\n";
		}
		if (tcase == "T") {
			for (int i=1; i<=d; i++) {
				res += (itop[v]-1);
				itop[v] = max(1, itop[v]-1);
				
				ileft[itop[v]] = min(ileft[itop[v]], itop[v]);
				iright[itop[v]] = max(iright[itop[v]], itop[v]);
			}
			cout << res << "\n";
		}
		if (tcase == "B") {
			for (int i=1; i<=d; i++) {
				res += (n-ibottom[v]);
				ibottom[v] = min(n, ibottom[v]+1);
			
				ileft[ibottom[v]] = min(ileft[ibottom[v]], ibottom[v]);
				iright[ibottom[v]] = max(iright[ibottom[v]], ibottom[v]);
			}
			cout << res << "\n";
		}
	}
	return 0;
}
