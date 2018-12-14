#include <iostream>
#define maxn 250+10
using namespace std;

int n;
int lab[maxn], u[100000], v[100000];

int getRoot(int u) {
	if (lab[u] == u) return u;
	else {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
}

void disjointSet(int r1, int r2) {
	if (r1<r2) lab[r2] = r1;
	else lab[r1] = r2;
}

int main() {
	int m, r1, r2, bohuhong;
	cin >> n >> m;
	for (int i=1; i<=m; i++) cin >> u[i] >> v[i];
	for (int i=1; i<=n; i++) lab[i] = i;
	for (int i=1; i<=m; i++) {
		r1 = getRoot(u[i]);
		r2 = getRoot(v[i]);
		if (r1!=r2) disjointSet(r1, r2);
	}
	bohuhong = 0;
	for (int i=2; i<=n; i++) {
		if (getRoot(i)!=1) {
			cout << i << endl;
			bohuhong++;
		}
	}
	
	if (bohuhong==0) cout << 0;
	return 0;
}
