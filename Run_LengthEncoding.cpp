/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
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

bool check[10000+10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	char cmd;
	string input;
	long lengthi;
	long count[1000];
	
	cin >> cmd;
	cin >> input;
	lengthi = input.length();
	
	memset(count, 0, sizeof(count));
	if (cmd == 'E') {
		FOR(i, 0, lengthi-1) {
			count[input[i]]++;
			if (i>=1 && input[i] != input[i-1]) {
				cout << input[i-1] << count[input[i-1]];
				count[input[i-1]] = 0;
			}
		}
		cout << input[lengthi-1] << count[input[lengthi-1]];
	}
	else {
		char tmp;
		FOR(i, 0, lengthi-1) {
			if (!isdigit(input[i])) tmp = input[i];
			else {
				FOR(j, 1, input[i]-'0') cout << tmp;
			}
		}
	}
	
	return 0;
}
