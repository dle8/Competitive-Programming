/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<ll, ll> pllll;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);	

	long tcount, tmp, m;
	long left[18], right[18];

	cin >> m;
	tmp = m;
	
	memset(left, 0, sizeof(left));
	memset(right, 0, sizeof(right));
	
	tcount = 0;
	while (tmp!=0) {
		++tcount;
		if ((tmp % 3) == 1) right[tcount] = 1;
		else if ((tmp % 3) == 2) {
			tmp+=1;
			left[tcount] = 1;	
		}
		tmp = tmp/3;
	}
	
	vector<long> leftScale, rightScale;
	leftScale.clear(); rightScale.clear();
	
	REP(i, tcount, 1) {
		if (right[i] == 1) rightScale.pb(pow(3, i-1));
		if (left[i] == 1) leftScale.pb(pow(3, i-1));
	}
	
	cout << leftScale.size() << " ";
	while (!leftScale.empty()) {
		cout << leftScale.back() << " ";
		leftScale.pop_back();
	}
	
	cout << "\n";
	
	cout << rightScale.size() << " ";
	while (!rightScale.empty()) {
		cout << rightScale.back() << " ";
		rightScale.pop_back();
	}
	
	return 0;
}
