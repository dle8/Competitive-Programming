#include <bits/stdc++.h>
#define maxn 10000+10
using namespace std;

int lab[maxn];

int getRoot(int u){
	if (lab[u]>0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	return u;
}

void disjointSet(int goc1, int goc2) {
	if (lab[goc1] == lab[goc2]) {
		lab[goc1]--;
		lab[goc2] = goc1;
	}
	else  {
		if (lab[goc1] < lab[goc2]) lab[goc2] = goc1;//thang cay co goc la goc 1 co chieu cao cao hon
		else lab[goc1] = goc2;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int p, x, y, z, r1, r2;
	for (int i=1; i<=maxn; i++) lab[i] = -1;//lab[goc] cua cay la -chieu cao cua cay
	cin >> p;
	for (int i=1; i<=p; i++) {
		cin >> x >> y >> z;
		r1 = getRoot(x);
		r2 = getRoot(y);
//		cout << r1 << " " << r2 << endl;
		if (z==1) {
			if (r1 != r2) disjointSet(r1, r2);
		}
		
		if (z==2) {
			cout << (r1==r2) << endl;	
		}
	}
	return 0;
}
