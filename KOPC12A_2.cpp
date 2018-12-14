#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define oo 1000000000000000000
#define maxn 10000+10
using namespace std;

typedef long long ll;

struct node {
	ll height, price;
};

node building[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll totalCost, oneFloor, res;
	long test, n, maxHeight;
	cin >> test;
	FOR(o, 1, test) {
		cin >> n;
		totalCost = 0;
		oneFloor = 0;
		maxHeight = 0;
		res = oo;
		FOR(i, 1, n) {
			cin >> building[i].height;
			if (building[i].height>maxHeight) maxHeight = building[i].height;	
		}
		FOR(i, 1, n) {
			cin >> building[i].price;
			totalCost+=(building[i].price*building[i].height);
			oneFloor+=building[i].price;
		}
		if (totalCost < res) res = totalCost;
		FOR(k, 1, maxHeight) {
			totalCost-=oneFloor;
			if (abs(totalCost)<res) res = abs(totalCost);
		}
		
		cout << res << "\n";
	}
	return 0;
}
