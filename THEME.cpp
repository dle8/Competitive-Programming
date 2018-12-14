/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define eps 1e-9

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<ll, ll> pllll;
typedef pair<ld, ld> Point;
typedef pair<Point, Point> line;
struct strLine { ld a, b, c; };

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

const double pi = 3.141592653589793;

ll gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
ll lcm(ll a, ll b) { return (a*b)/gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

#define maxn 5000 + 10
#define oo 1000000000

string diff[maxn];
long n, note[maxn];

bool existTheme(long length) { // length is the number of node in the Maximum Theme
	hash<string> str_hash;
	int h[maxn];
	string str[maxn];
	str[1] = "";
	FOR(i, 1, length - 1) {
		str[1] += diff[i];
		h[1] = int(str_hash(str[1]));
	}

	FOR(i, 2, n - length + 1) {
		string tmp = str[i - 1];
		tmp.erase(tmp.begin());
		str[i] = tmp + diff[i + length - 1 - 1];
		h[i] = int(str_hash(str[i]));
	}

	unordered_map<ll, int> pos;
	FOR(i, 1, n - length + 1) {
		if (pos[h[i]] == 0) {
			pos[h[i]] = i;
		}
		else {
			if (i >= pos[h[i]] + length - 1 - 1) return true;
		}
	}

	return false;
}

int main() {
	fio;

	cin >> n;

	FOR(i, 1, n) {
		cin >> note[i];
		if (i == 1) continue;
		diff[i - 1] = "";
		diff[i - 1] += char(note[i] - note[i - 1] + 100); // change the number into char -> hashing for string
	}

	long d = 1;
	long c = n;

	while (d <= c) {
		long mid = (d + c) / 2; // mid the length of the longest theme
		if (existTheme(mid) && 2 * mid <= n) d = mid + 1;
		else c = mid - 1;
	}

	return cout << ((c >= 5) ? c : 0), 0;
}
