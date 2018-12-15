/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define x first
#define y second
#define pb push_back
#define sz(x) int(x.size())
#define eps 1e-18

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> Point;
#define maxn 1500 + 10
Point p[maxn];
vector<ld> lines[maxn];
long vertical[maxn], horizontal[maxn];

bool smallerOrEqual(ld num1, ld num2) {
	return (num1 - num2 == 0 || num1 - num2 < -eps);
}

bool largerOrEqual(ld num1, ld num2) {
	return (num1 - num2 == 0 || num1 - num2 > eps);
}

long findLow(long vertex, ld key) {
	long d = 0;
	long c = sz(lines[vertex]) - 1;
	while (d <= c) {
		long mid = (d + c) / 2;
		if (largerOrEqual(lines[vertex][mid], key)) c = mid - 1;
		else d = mid + 1;
	}
	return d;
}

long findHigh(long vertex, ld key) {
	long d = 0;
	long c = sz(lines[vertex]) - 1;
	while (d <= c) {
		long mid = (d + c) / 2;
		if (smallerOrEqual(lines[vertex][mid], key)) d = mid + 1;
		else c = mid - 1;
	}
	return c;
}

int main() {
	fio;
	ll n;
	cin >> n;
	FOR(i, 1, n) cin >> p[i].x >> p[i].y;
	FOR(i, 1, n - 1)
	FOR(j, i + 1, n) {
		if (p[i].x == p[j].x) vertical[i]++, vertical[j]++;
		else if (p[i].y == p[j].y) horizontal[i]++, horizontal[j]++;
		else {
			ld reverseSlope = (p[i].x - p[j].x) / ld(p[j].y - p[i].y);
			lines[i].pb(reverseSlope);
			lines[j].pb(reverseSlope);
		}
	}
	FOR(i, 1, n) {
		sort(lines[i].begin(), lines[i].end(), [](ld x, ld y) {
			return (x - y < -eps);
		});
	}
	ll res = 0;
	FOR(i, 1, n - 1)
	FOR(j, i + 1, n) {
		if (p[i].x == p[j].x) res += (horizontal[i] + horizontal[j]);
		else if (p[i].y == p[j].y) res += (vertical[i] + vertical[j]);
		else {
			ld slope = (p[j].y - p[i].y) / ld(p[j].x - p[i].x);
			long lowi = findLow(i, slope); long highi = findHigh(i, slope);
			long lowj = findLow(j, slope); long highj = findHigh(j, slope);
			if (0 <= lowi && lowi <= sz(lines[i]) - 1 && lines[i][lowi] - slope == 0) res += (highi - lowi + 1);
			if (0 <= lowj && lowj <= sz(lines[j]) - 1 && lines[j][lowj] - slope == 0) res += (highj - lowj + 1);
		}
	}
	cout << res / 2;
	return 0;
}
