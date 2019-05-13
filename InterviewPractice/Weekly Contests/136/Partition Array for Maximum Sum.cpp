typedef long long ll;
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define sz(x) int(x.size())
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

#define maxn 500 + 10

class Solution {
public:

    int maxSum[maxn], dp[maxn], it[4 * maxn];

    void update(int cs, int u, int v, int i, long val) {
        if (i < u || v < i) return; //neu i khong nam trong doan [u, v]
        it[cs] = max(it[cs], val);
        if (u == v) return;//khi (u==v) cung chinh la (u==v==i) va day la nut la cua cay
        int mid = (u + v) / 2;
        update(2 * cs, u, mid, i, val);
        update(2 * cs + 1, mid + 1, v, i, val);
    }

    int getMax(int cs, int u, int v, int l, int r) {
        if (r < u || l > v) return 0;
        if (l <= u && v <= r) return it[cs];
        int mid = (u + v) / 2;
        return max(getMax(2 * cs, u, mid, l, r), getMax(2 * cs + 1, mid + 1, v, l, r));
    }

    int maxSumAfterPartitioning(vector<int>& a, int k) {
        memset(maxSum, 0, sizeof(maxSum));
        memset(dp, 0, sizeof(dp));
        dp[0] = a[0];
        maxSum[0] = dp[0];
        int n = sz(a);
        FOR(i, 0, n - 1) update(1, 1, n, i + 1, a[i]);
        FOR(j, 1, n - 1) {
            FOR(i, max(j - k + 1, 0), j) {
                dp[j] = max(dp[j], ((i == 0) ? 0 : maxSum[i - 1]) + getMax(1, 1, n, i + 1, j + 1) * (j - i + 1));
            }
            maxSum[j] = max(maxSum[j], dp[j]);
        }
        return dp[n - 1];
    }
};
