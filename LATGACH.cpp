#include <bits/stdc++.h>
#define mp make_pair
#define debug(matrix) cout << matrix.first.first << " " << matrix.first.second << " " << matrix.second.first << " " << matrix.second.second << endl
using namespace std;

typedef unsigned long long ul;
typedef pair<ul, ul> ll;
typedef pair<ll, ll> llll;

int n;

llll multiple(llll ma, llll mb) {
	ul topLeft = ma.first.first*mb.first.first+ma.first.second*mb.second.first;
	ul topRight = ma.first.first*mb.first.second+ma.first.second*mb.second.second;
	ul bottomLeft = ma.second.first*mb.first.first+ma.second.second*mb.second.first;
	ul bottomRight = ma.second.first*mb.first.second + ma.second.second*mb.second.second;
	return mp(mp(topLeft, topRight), mp(bottomLeft, bottomRight));
}

llll getMatrix(int k) {
	if (k==1) return mp(mp(1, 1), mp(1, 0));
	llll half = getMatrix(k/2);
	if (k%2==0) return multiple(half, half);
	return multiple(multiple(half, half), mp(mp(1, 1), mp(1, 0)));
}

ul latgach(int n) {
	if (n==1) return 1;
	if (n==2) return 2;
	llll matrix = getMatrix(n-2);
	return 2*matrix.first.first+matrix.second.first;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int itest;
	cin >> itest;
	for (int i=1; i<=itest; i++) {
		cin >> n;
		cout << latgach(n) << "\n";
	}
	return 0;
}
