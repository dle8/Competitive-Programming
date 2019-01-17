/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define maxn 20
ll a[2 * maxn], tleft[1 << maxn], tright[1 << maxn];
map<ll, ll> countRight;

ll getBit(ll index, ll x) {
  return (1 & (x >> index));
}

int main() {
	// fio;
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ll n, sum = 0;
  cin >> n;
  FOR(i, 1, n) {
    cin >> a[i];
    sum += a[i];
  }
  // fclose(stdin);

  ll cntl = 0;
  FOR(i, 0, (1 << (n / 2)) - 1) {
    ll tmp = 0;
    FOR(j, 0, n / 2 - 1) if (getBit(j, i)) tmp += a[j + 1];
    tleft[++cntl] = tmp;
  }
  sort(tleft + 1, tleft + 1 + cntl);

  ll cntr = 0;
  FOR(i, 0, (1 << (n - n / 2)) - 1) {
    ll tmp = 0;
    FOR(j, 0, n - n / 2 - 1) if (getBit(j, i)) tmp += a[j + n - n / 2 + (n % 2 == 0)];
    tright[++cntr] = tmp;
    countRight[tmp]++;
  }
  sort(tright + 1, tright + 1 + cntr);

  ll way = 0, maxSum = 0;
  FOR(i, 1, cntl) {
    ll g = sum - tleft[i] * 2;
    if (g < 0) continue;
    ll d = 1;
    ll c = cntr;
    while (d <= c) {
      ll mid = (d + c) / 2;
      if (2 * tright[mid] <= g) d = mid + 1;
      else c = mid - 1;
    }
    if (c == 0) break;
    if (tleft[i] + tright[c] > maxSum) {
      maxSum = tleft[i] + tright[c];
      way = countRight[tright[c]];
    }
    else if (tleft[i] + tright[c] == maxSum) way += countRight[tright[c]];
  }
  ll minDiff = sum - 2 * maxSum;
  cout << minDiff << " " << ((minDiff == 0) ? way / 2 : way);
	return 0;
}
