/*
Author: Dung Tuan Le
University of Rochester
Created: 12/10/2018
*/

/*
Complexity: O(n)
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

ll gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); } 
ll lcm(ll a, ll b) { return (a*b)/gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

#define maxn 10000 + 10

long a[maxn];

int main() {
	fio;
	
	long n, x, fiPointer, sePointer, subSum;	
	cin >> n >> x;
	FOR(i, 1, n) cin >> a[i];
	
	fiPointer = 0, sePointer = 0;
	subSum = 0;
	while (fiPointer < n) {
		fiPointer ++;
		if (fiPointer > sePointer) sePointer = fiPointer;
		while (subSum + a[sePointer] <= x) subSum += a[sePointer ++];
		sePointer--;
		cout << subSum << " " << fiPointer << " " << sePointer << "\n";
		if (subSum == x) return cout << fiPointer << " " << sePointer, 0;
	}
	
	cout << "Not exist";
	return 0;
}
