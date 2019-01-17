/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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

#define maxn 1000000 + 10
long knap[maxn], a[maxn], b[maxn];
unordered_map<ll, ll> pos;

void print(long i, long j) {
	cout << j - i + 1 << '\n';
	FOR(k, i, j) cout << k << " ";
	cout << '\n';
}

int main() {
	fio;

	long n;
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		a[i] = a[i - 1] + a[i];
	}

	FOR(i, 1, n) {
		cin >> b[i];
		b[i] = b[i - 1] + b[i];
	}

	bool swapped = false;
	if (a[n] > b[n]) {
		swap(a, b);
		swapped = true;
	}

	long pointer = 0;
	FOR(i, 1, n) {
		while (b[pointer + 1] <= a[i] && pointer + 1 <= n) pointer++;
		knap[i] = pointer;
	}

	pos.clear();
	knap[0] = 0;
	pos[0] = 0;

	FOR(i, 1, n) {
		ll diff = a[i] - b[knap[i]];
		if (pos[diff] != 0 || diff == 0) {
			if (swapped) {
				print(knap[pos[diff]] + 1, knap[i]);
				print(pos[diff] + 1, i);
			}
			else {
				print(pos[diff] + 1, i);
				print(knap[pos[diff]] + 1, knap[i]);
			}
			return 0;
		}
		else pos[diff] = i;
	}

	// cout << -1;

	return 0;
}
