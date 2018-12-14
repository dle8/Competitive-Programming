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

int bs(vector<int> &stores, int key) {
	int d = 0;
	int c = int(stores.size() - 1);
	while (d <= c) {
		int mid = (d+c)/2;
		if (stores[mid] <= key) d = mid + 1;
		else c = mid - 1;
	}
	return c;
}

vector<int> solution(vector<int> &stores, vector<int> &houses) {
	sort(stores.begin(), stores.end());
	sort(houses.begin(), houses.end());
	
	vector<int> res; 
	FOR(i, 0, int(houses.size())-1) {
		int index = bs(stores, houses[i]);
		if (index == -1) res.pb(stores[0]);
		else if (index >= int(stores.size())-1) res.pb(stores[int(stores.size())-1]);
		else {
			if (abs(houses[i] - stores[index]) > abs(houses[i] - stores[index + 1])) res.pb(stores[index + 1]);
			else res.pb(stores[index]);
		}
	}
	return res;
}

int main() {
	fio;
		
	long m, n, x;
	cin >> m >> n;
	vector<int> houses; houses.clear();
	vector<int> stores; stores.clear();
	FOR(i, 1, m) {
		cin >> x;
		stores.pb(x);
	} 
	
	FOR(i, 1, n) {
		cin >> x;
		houses.pb(x);
	}
	
	vector<int> res = solution(stores, houses);
	for (auto iter = res.begin(); iter != res.end(); iter++)
		cout << *iter << " ";
	return 0;
}
