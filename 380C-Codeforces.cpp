#include <bits/stdc++.h>
#include <string>
#define maxn 1000000+10
using namespace std;

string input;

struct node {
	int optimal = 0;
	int open  = 0;
	int close = 0;
};

node it[4*maxn];

int min(int a, int b) {
	if (a<=b) return a;
	else return b;
}

void update(int cs, int u, int v, int i, char c) {
	if (i<u || i>v) return;
	if (c == '(') it[cs].open++;
	if (c == ')') {
		if (it[cs].open>0) {
			it[cs].optimal++;
			it[cs].open--;
		}
		else it[cs].close++;
	}
	if (u==v) return;
	int mid = (u+v)/2;
	update(2*cs, u, mid, i, c);
	update(2*cs+1, mid+1, v, i, c);	
}

node getMax(int cs, int u, int v, int l, int r) {
	node total;
	if (r<u || l>v) return total;
	if (l<=u && v<=r) return it[cs];
	int mid = (u+v)/2;
	node left = getMax(2*cs, u, mid, l, r);
	node right = getMax(2*cs+1, mid+1, v, l, r);
	int extra = min(left.open, right.close);
	total.optimal = left.optimal + right.optimal + extra;
	total.open = left.open + right.open - extra;
	total.close = left.close + right.close -extra;
	return total;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, u, v;
	cin >> input;
	n = input.length();
	cin >> m;
	for (int i=1; i<=n; i++)
		update(1, 1, n, i, input[i-1]);
	for (int i=1;  i<=m; i++) {
		cin >> u >> v;
		cout << 2*getMax(1, 1, n, u, v).optimal << endl;//phai nhan 2 vi tinh do dai xau. optimal chi la so cap ()
	}
	return 0;
}
