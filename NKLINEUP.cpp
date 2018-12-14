#include <iostream>
#define mp make_pair
#define oo 1e9
using namespace std;

int a[50000];
pair<int, int> it[200000];

int max(int a, int b) {
	if (a>=b) return a;
	else return b;
}

int min(int a, int b) {
	if (a<=b) return a;
	else return b;
}

void update(int index, int u, int v, int i, int val) {
	if (i<u || v<i) return;
	it[index].first = max(it[index].first, val);
	it[index].second = min(it[index].second, val);
	if (u==v) return;
	long mid = (u+v)/2;
	update(2*index+1, u, mid, i, val);
	update(2*index+2, mid+1, v, i, val);
}

pair<int, int> findExtreme(int index, int u, int v, int x, int y) {
	pair<int, int> p1, p2, result;
	if (y<u || v<x) return mp(-oo, oo);
	if (x<=u && v<=y) return it[index];
	long mid = (u+v)/2;
	p1 = findExtreme(2*index+1, u, mid, x, y);
	p2 = findExtreme(2*index+2, mid+1, v, x, y);
	return mp(max(p1.first, p2.first), min(p1.second, p2.second));
}

int main() {
	int n, q;
	pair<int, int> foo;
	
	cin >> n >> q;
	
	for (int i=0; i<200000; i++) {
		it[i].first = 0;
		it[i].second = 1000001;
	}
	
	for (int i=0; i<n; i++) {
		cin >> a[i];
		update(0, 0, n-1, i, a[i]);
	}
	
	for (int i=0; i<q; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		foo = findExtreme(0, 0, n-1, a, b);
		cout << foo.first - foo.second << "\n";
	}
	return 0;
}
