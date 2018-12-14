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

#define oo 1000000000

struct compare {

vector<vi> d;

public:
	compare(vector<vi> d) {
		this.d = d;
	}

	bool operator()(const pii &x, const pii &y) {
		return (d[x.fi][x.se] > d[y.fi][y.se]);
	}
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
				vector<vi> d(int(grid.size()), vi(int(grid.size()), oo));
				d[0][0] = 0;

				priority_queue<pii, vector<pii>, compare()> q;
    }
};

int main() {
	fio;

	cin >> m >> n;
	vector<vi> grid; grid.clear();
	FOR(i, 1, m) {
			vi row; row.clear();
			FOR(j, 1, n) {
				cin >> num;
				row.pb(num);
			}
			grid.pb(row);
	}

	Solution sol;
	cout << sol.minPathSum(grid);

	return 0;
}
