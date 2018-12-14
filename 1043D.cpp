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

#define maxn 100000 + 10
#define maxm 10 + 5

long a[maxm][maxn], pos[maxn], reach[maxn];

int main() {
	fio;

	long m, n;
	cin >> n >> m;
	// change the permutations such as the first one is 1, 2, 3, ..., n
	FOR(i, 1, m)
	FOR(j, 1, n) {
		cin >> a[i][j];
		if (i == 1) {
			pos[a[i][j]] = j;
			a[i][j] = j;
		}
		else {
			a[i][j] = pos[a[i][j]];
		}
	}

	// for all i in all permutations find reach[i]: the length of the longest subarrays that start at i
	// that takes the form of i, i + 1, i + 2, ... using two pointer
	FOR(i, 1, n) {
		reach[i] = n + 1 - i;
	}

	FOR(i, 2, m) {
		long fiPointer = 1, sePointer;
		while (fiPointer <= n) {
			sePointer = fiPointer;

			FOR(j, fiPointer + 1, n) {
				if (a[i][j] == a[i][j - 1] + 1) sePointer = j;
				else {
					sePointer = j - 1;
					break;
				}
			}

			FOR(j, fiPointer, sePointer) {
				reach[a[i][j]] = min(reach[a[i][j]], sePointer - j + 1);
			}
			fiPointer = sePointer + 1;
		}
	}

	ll res = 0;
	FOR(i, 1, n) {
		res += reach[i];
	}

	cout << res;

	return 0;
}
