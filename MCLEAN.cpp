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

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll lcm(ll a, ll b) { return (a*b)/__gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

void solve()
{
    int k;
    cin >> k;
    vector<int> arr(7);
    int sum = 0;
    for (int i = 0; i < 7; ++i){
        cin >> arr[i];
        sum += arr[i];
        if (i > 0)
            arr[i] += arr[i - 1];
    }
    if (k <= sum)
    {
        int mi = 9;
        for (int i = 0; i < 7; ++i)
        {
            int curr = 0;
            for (int j = 0; j < 7; ++j)
            {
                curr += arr[(j + i) % 7] - ((i + j) % 7 > 0 ? arr[(i + j) % 7 - 1] : 0);
                if (curr == k)
                {
                    mi = min(mi, j + 1);
                    break;
                }
            }
            debug(i);
            debug(curr);
        }
        cout << mi << '\n';
        return;
    }
    int mi = 1e9;
    for (int i = 0; i < 7; ++i)
    {
        int curr = 7 - i;
        int tk = k;
        tk -= sum - (i > 0 ? arr[i - 1] : 0);
        if (tk % sum){
        curr += (tk / sum) * 7;
        tk %= sum;
        }
        else
        {
            curr += ((tk - sum) / sum) * 7;
            tk = sum;
        }
        if (tk != 0)
            for (int j = 0; j < 7; ++j)
                if (arr[j] == tk)
                {
                    curr += j + 1;
                    break;
                }
        mi = min(mi, curr);
    }
    cout << mi << '\n';
    return;

}

int main() {
	fio;

  int t;
  cin >> t;
  while (t)
  {
      solve();
      --t;
  }

	return 0;
}
