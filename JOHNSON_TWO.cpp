#include <bits/stdc++.h>
#define maxn 10000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

struct node {
	long a, b;
};

node detail[maxn];
long n1[maxn], n2[maxn], n;

bool comparen1(const long&cs1, const long&cs2) {
	return (detail[cs1].a<detail[cs2].a);
}

bool comparen2(const long&cs1, const long&cs2) {
	return (detail[cs1].b>detail[cs2].b);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	FOR(i, 1, n) cin >> detail[i].a;
	
	FOR(i, 1, n) cin >> detail[i].b;
	
	long indexn1 = 0, indexn2 = 0;
	
	FOR(i, 1, n) {
		if (detail[i].a<=detail[i].b) {
			indexn1++;
			n1[indexn1] = i;
		}
		else {
			indexn2++;
			n2[indexn2] = i;
		}
	}
	
	sort(n1+1, n1+1+indexn1, comparen1);
	sort(n2+1, n2+1+indexn2, comparen2);
	
	FOR(i, indexn1+1, n) n1[i] = n2[i-indexn1];
	
	long sa = detail[n1[1]].a;
	long sb = detail[n1[1]].a+detail[n1[1]].b;
	
	FOR(i, 2, n) {
		sa+=detail[n1[i]].a;
		if (sa>=sb) sb = sa+detail[n1[i]].b;
		else sb+=detail[n1[i]].b;
	}
	
	cout << sb << "\n";
	FOR(i, 1, n) cout << n1[i] << " ";
	
	return 0;
}
