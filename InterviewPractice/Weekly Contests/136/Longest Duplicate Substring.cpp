#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define FORALL(iter, x) for (auto iter = x.begin(); iter != x.end(); iter++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define eps 1e-9
#define sz(x) int(x.size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll p1 = 36447793;
const ll p2 = 76446439;
const ll mod = 1e9 + 7;
const ll maxn = 1e5 + 10;

class Solution {
public:

		ll tpow1[maxn], tpow2[maxn];

		ll sub(ll a, ll b) {
			return ((a - b) % mod + mod) % mod;
		}

		ll add(ll a, ll b) {
			return (a + b) % mod;
		}

		ll mul(ll a, ll b) {
			return ((a % mod) * (b % mod)) % mod;
		}

    string longestDupSubstring(string s) {
			ll d = 1;
			ll n = sz(s);
			ll c = n;
			tpow1[0] = 1;
            tpow2[0] = 1;
			FOR(i, 1, 100000) {
                tpow1[i] = mul(tpow1[i - 1], p1);
                tpow2[i] = mul(tpow2[i - 1], p2);
            }
			set<pair<ll, ll>> mset;
			ll start = -1;
			while (d <= c) {
				ll mid = (d + c) / 2;
				mset.clear();
                pair<ll, ll> tmp = {0, 0};
				FOR(i, 0, mid - 1) {
                    tmp.fi = add(tmp.fi, mul(s[i] - 'a', tpow1[mid - 1 - i]));
                    tmp.se = add(tmp.se, mul(s[i] - 'a', tpow2[mid - 1 - i]));
                }
				mset.insert(tmp);
				bool flag = false;
				FOR(i, 1, n - mid) {
					tmp.fi = sub(tmp.fi, mul(s[i - 1] - 'a', tpow1[mid - 1]));
					tmp.fi = mul(tmp.fi, p1);
					tmp.fi = add(tmp.fi, s[mid + i - 1] - 'a');

                    tmp.se = sub(tmp.se, mul(s[i - 1] - 'a', tpow2[mid - 1]));
					tmp.se = mul(tmp.se, p2);
					tmp.se = add(tmp.se, s[mid + i - 1] - 'a');
					if (mset.find(tmp) != mset.end()) {
						flag = true;
						start = i;
						break;
					}
					mset.insert(tmp);
				}
				if (flag) d = mid + 1;
				else c = mid - 1;
			}
			if (start == -1) return "";
			return s.substr(start, c);
    }
};
