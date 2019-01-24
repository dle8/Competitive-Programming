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
#define oo 1000000000
long a[2 * maxn], lengthOfConse[maxn], it[4 * 2 * maxn], n, lazy[4 * 2 * maxn], maxLength[maxn];

void update(long index, long u, long v, long l, long r, long val) {
	if (r < u || v < l) return;
	if (l <= u && v <= r) {
		lazy[index] += val;
		return;
	}
	long mid = (u + v) / 2;
	update(2 * index, u, mid, l, r, val);
	update(2 * index + 1, mid + 1, v, l, r, val);
	it[index] = max(it[2 * index] + lazy[2 * index], it[2 * index + 1] + lazy[2 * index + 1]);
}

long rangeMax(long index, long u, long v, long l, long r) {
	if (r < u || v < l) return -oo;
	if (l <= u && v <= r) return it[index] + lazy[index];
	long mid = (u + v) / 2;
	return max(rangeMax(2 * index, u, mid, l, r), rangeMax(2 * index + 1, mid + 1, v, l, r)) + lazy[index];
}

int main() {
	fio;

	long q, k;
	string queries;


	memset(lengthOfConse, 0, sizeof(lengthOfConse));
	memset(it, 0, sizeof(it));
	memset(lazy, 0, sizeof(lazy));
	memset(maxLength, 0, sizeof(maxLength));

	cin >> n >> q >> k;
	FOR(i, 1, n) cin >> a[i];

	cin >> queries;

	FOR(i, n + 1, (2 * n))
		a[i] = a[i - n];

	queue<long> Queue;

	FOR(i, 1, n) {
		if (Queue.empty()) {
			if (a[i] == 1) Queue.push(i);
			continue;
		}

		while (i - Queue.front() >= k) {
			lengthOfConse[Queue.front()] = k;
			Queue.pop();
		}

		if (a[i] == 0) {
			while (!Queue.empty()) {
				lengthOfConse[Queue.front()] = i - Queue.front();
				Queue.pop();
			}
		}
		else Queue.push(i);
	}

	queue<long> tmp = Queue;

	FOR(i, 1, n)
		update(1, 1, (2 * n), i, i, lengthOfConse[i]);

	while (!tmp.empty()) {
		update(1, 1, (2 * n), tmp.front(), tmp.front(), n - tmp.front() + 1);
		tmp.pop();
	}

	maxLength[1] = rangeMax(1, 1, (2 * n), 1, n);

	FOR(i, 2, n) {
		if (a[i + n - 1] == 0) {
			while (!Queue.empty()) {
				Queue.pop();
			}
		}

		while (!Queue.empty() && i + n - 1 - Queue.front() >= k) {
			Queue.pop();
		}

		if (a[i + n - 1] == 1) {
			if (!Queue.empty()) {
				update(1, 1, (2 * n), Queue.front(), i + n - 2, 1);
			}
			update(1, 1, (2 * n), i + n - 1, i + n - 1, 1);
			Queue.push(i + n - 1);
		}

		maxLength[i] = rangeMax(1, 1, (2 * n), i, i + n - 1);
	}

	long left = 1;
	FOR(i, 0, int(queries.size()) - 1) {
		if (queries[i] == '!') left++;
		if (left > n) left = 1;
		if (queries[i] == '?') cout << maxLength[left] << "\n";
	}

	return 0;
}
