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

#define maxn 1000 + 10
long rival[2 * maxn], power[2 * maxn];
bool check[2 * maxn];
pll oppo[2 * maxn];

struct cmp {
	bool operator()(const long&x, const long&y) {
		return power[x] < power[y];
	}
};

int main() {
	fio;

	long n, m, tmp, move, a, b, t;
	cin >> n >> m;
	FOR(i, 1, (2 * n)) cin >> power[i];
	FOR(i, 1, m) {
		cin >> oppo[i].fi >> oppo[i].se;
		if (power[oppo[i].fi] < power[oppo[i].se]) swap(oppo[i].fi, oppo[i].se);
		rival[oppo[i].fi] = oppo[i].se;
		rival[oppo[i].se] = oppo[i].fi;
	}

	cin >> t;

	sort(oppo + 1, oppo + 1 + m, [](pll x, pll y) {
		return power[x.fi] > power[y.fi];
	});

	long index = 1;

	priority_queue<long, vl, cmp> pq;
	FOR(i, 1, (2 * n)) pq.push(i);
	memset(check, false, sizeof(check));
	tmp = 0;
	FOR(i, 1, n) {
		if (t == 1) {
			while (check[oppo[index].fi] || check[oppo[index].se]) {
				index++;
				if (index > m) break;
			}
			if (index <= m ) {
				cout << oppo[index].fi << '\n';
				cout.flush();
				check[oppo[index++].fi] = true;
			}
			else {
				while (!pq.empty() && check[pq.top()]) pq.pop();
				if (!pq.empty()) {
					cout << pq.top() << '\n';
					check[pq.top()] = true;
					pq.pop();
					cout.flush();
				}
			}
			cin >> move;
			check[move] = true;
			if (rival[move] != 0 && !check[rival[move]]) tmp = move;
		}
		else {
			cin >> move;
			check[move] = true;
			if (rival[move] != 0 & !check[rival[move]]) {
				cout << rival[move] << '\n';
				check[rival[move]] = true;
				cout.flush();
			}
			else {
				while (check[oppo[index].fi] || check[oppo[index].se]) {
					index++;
					if (index > m) break;
				}
				if (index <= m) {
					cout << oppo[index].fi << '\n';
					cout.flush();
					check[oppo[index++].fi] = true;
				}
				else {
					while (!pq.empty() && check[pq.top()]) pq.pop();
					if (!pq.empty()) {
						cout << pq.top() << '\n';
						check[pq.top()] = true;
						pq.pop();
						cout.flush();
					}
				}
			}
		}
	}

	return 0;
}
