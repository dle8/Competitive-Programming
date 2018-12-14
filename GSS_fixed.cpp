#include <bits/stdc++.h>
#define maxn 50000+10
using namespace std;

struct node {
	int max = -1000000000;
	int sumMax = 0;
};

int max(int a, int b) {
	if (a>=b) return a;
	else return b;
}

node it[4*maxn];
int a[maxn];
int n, m;

void update(int cs, int u, int v, int i, int val) {
	if (u == i && v == i) {
		it[cs].max = val;
		it[cs].sumMax = val;
		return;
	}
	int mid = (u+v)/2;
	if (i<=mid) {
		update(2*cs, u, mid, i, val);
		it[cs].max = max(it[cs].max, it[2*cs].max);
		if (it[cs].sumMax<it[cs].sumMax+val) 
			it[cs].sumMax+= val;
	}
	else {
		update(2*cs+1, mid+1, v, i, val);
		it[cs].max = max(it[cs].max, it[2*cs+1].max);
		if (it[cs].sumMax<it[cs].sumMax+val)
			it[cs].sumMax+=val;
	}
}

node itMax(int cs, int u, int v, int x, int y) {
	node p1, p2, temp;
	int mid;
	if (u==x && v==y) return it[cs];
	
	mid = (u+v)/2;
	if (y<=mid) return itMax(2*cs, u, mid, x, y);
	if (x>=mid+1) return itMax(2*cs+1, mid+1, v, x, y);
	
	p1 = itMax(2*cs, u, mid, x, mid);
	p2 = itMax(2*cs+1, mid+1, v, mid+1, y);
	temp.max = max(p1.max, p2.max);
	if (p1.sumMax==0 && p2.sumMax==0) return temp;
	if (p1.sumMax==0 || p2.sumMax==0) {
		temp.sumMax = max(p1.sumMax, p2.sumMax);
		return temp;
	}
	temp.sumMax =  p1.sumMax + p2.sumMax;
	return temp;	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x, y;
	node temp;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		update(1, 1, n, i, a[i]);		
	}
	cin >> m;
	for (int i=1; i<=m; i++) {
		cin >> x >> y;
		temp = itMax(1, 1, n, x, y);
		if (temp.sumMax==0) cout << temp.max << endl;
		else cout << temp.sumMax << endl;
	}
	return 0;
}
