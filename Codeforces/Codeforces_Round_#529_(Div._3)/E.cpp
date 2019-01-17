#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define REPD(i,a) for (int i = a; i > 0; i--)

#define ll long long
#define fi first
#define se second

typedef pair<int, int> pii;
typedef pair< ll, ll > pll;

#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL

#define debug(x) { cout << "---> " << #x << " = " << x << endl;  }
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

const ll MN = 1e6+5;

ll n, m, it[MN << 2], a[MN], lazy[MN<<2];
char temp[MN];

void build(ll l, ll r, ll pos) {
    if(l == r) {
        it[pos] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(l, mid, pos<<1);
    build(mid + 1, r, pos<<1|1);
    it[pos] = min(it[pos<<1], it[pos<<1 | 1]);
    return;
}

void update(ll l, ll r, ll u, ll v, ll val, ll pos) {
    if(l > r) return;
    if(lazy[pos] != 0) {
        it[pos] += lazy[pos];
        if(l != r) {
            lazy[pos<<1] += lazy[pos];
            lazy[pos<<1 | 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(u > r or v < l) return;
    if(u <= l and r <= v) {
        it[pos] += val;
        if(l != r) {
            lazy[pos<<1] += val;
            lazy[pos<<1 | 1] += val;
        }
        return;
    }
    ll mid = (l + r) >> 1;
    update(l, mid, u, v, val, pos<<1);
    update(mid + 1, r, u, v, val, pos<<1|1);
    it[pos] = min(it[pos<<1],it[pos<<1 | 1]);
    return;
}

ll query(ll l, ll r, ll u, ll v, ll pos) {
    if(l > r) return inf;
    if(lazy[pos] != 0) {
        it[pos] += lazy[pos];
        if(l != r) {
            lazy[pos<<1] += lazy[pos];
            lazy[pos<<1 | 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(u == 0) return 0;
    if(v < l or u > r) return inf;
    if(u <= l and r <= v) return it[pos];
    ll mid = (l + r) >> 1;
    return min(query(l, mid, u, v, pos<<1),
            query(mid + 1, r, u, v, pos<<1 | 1));
}

int main() {
  fio;
    cin >> n;
    cin >> temp;
    REP(i, n) {
        if(temp[i] == '(') a[i+1] = a[i] + 1;
        else a[i+1] = a[i] - 1;
    }
    build(1, n, 1);
    long tcount = 0;
    FOR(i, 1, n) {
      if (temp[i - 1] == '(') {
        update(1, n, i, n, -2, 1);
        temp[i - 1] = ')';

        ll aR   = query(1, n, n, n, 1);
        ll aL1  = query(1, n, 0, 0, 1);
        ll mnLR = query(1, n, 1, n, 1);
        if(aR == aL1 and mnLR == aL1) tcount++;

        update(1, n, i, n, 2, 1);
        temp[i - 1] = '(';
      }
      else {
        update(1, n, i, n, 2, 1);
        temp[i - 1] = '(';

        ll aR   = query(1, n, n, n, 1);
        ll aL1  = query(1, n, 0, 0, 1);
        ll mnLR = query(1, n, 1, n, 1);
        if(aR == aL1 and mnLR == aL1) tcount++;

        update(1, n, i, n, -2, 1);
        temp[i - 1] = ')';
      }
    }

    cout << tcount;
}
