#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define maxn 100000+10
#define maxm 200000+10
using namespace std;

struct node {
	long brackets, left, right;
};

node it[4*maxn];
long n, m;
string s;

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

void update(long cs, long u, long v, long i, char c) {
	if (u==i && v==i) {
		if (c=='(') {
			it[cs].right = 1;
			it[cs].left = 0;
		}
		else {
			it[cs].left = 1;
			it[cs].right = 0;
		}
		return;
	}
	long mid = (u+v)/2;
	if (i<=mid) {
		update(2*cs, u, mid, i, c);
		it[cs].left = (it[2*cs].left==(mid-u+1))?it[2*cs].left+it[2*cs+1].left:it[2*cs].left;
	}
	else {
		update(2*cs+1, mid+1, v, i, c);
		it[cs].right = (it[2*cs+1].right==(v-mid))?it[2*cs+1].right+it[2*cs].right:it[2*cs+1].right;
	}
	it[cs].brackets = it[2*cs].brackets+it[2*cs+1].brackets+min(it[2*cs].right, it[2*cs+1].left);
}

node getBrackets(long cs, long u, long v, long l, long r) {
	node temp;
	if (r<u || v<l) {
		temp.left = 0;
		temp.right = 0;
		temp.brackets = 0;
		return temp;
	}
	if (l<=u && v<=r) return it[cs];
	long mid = (u+v)/2;
	node left = getBrackets(2*cs, u, mid, l, r);
	node right = getBrackets(2*cs+1, mid+1, v, l, r);
	temp.left = (left.left==(mid-u+1))?left.left+right.left:left.left;
	temp.right = (right.right==(v-mid))?right.right+left.right:right.right;
	temp.brackets = left.brackets+right.brackets+min(left.right, right.left);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	node left, right;
	long l, r, tcase;
	char c;
	cin >> n >> m;
	cin >> s;
	FOR(i, 1, n) update(1, 1, n, i, s[i-1]);
	
	FOR(i, 1, m) {
		cin >> tcase;
		if (tcase==0) {
			cin >> l;
			cin >> c;
			update(1, 1, n, l, c);
		}
		else {
			cin >> l >> r;
			if ((r-l+1)%2!=0) {
				cout << 0; 
				continue;
			}
			node range = getBrackets(1, 1, n, l, r);
			if (range.brackets*2==(r-l+1)) cout << 1;
			else cout << 0;			
		}
	}
	return 0;
}
