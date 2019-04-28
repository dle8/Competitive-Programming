#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define FORALL(iter, x) for (auto iter = x.begin(); iter != x.end(); iter++)
#define fi first
#define se second
#define sz(x) int(x.size())
#define maxn 500 + 10
typedef pair<int, int> pii;
const int inf = 1e9;

int max(int a, int b) {
    return (a >= b) ? a : b;
}

class Solution {
public:

    int maxRange[maxn][maxn], dp[maxn][maxn];

    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        memset(maxRange, 0, sizeof(maxRange));
        memset(dp, 0, sizeof(dp));
        int m = sz(a);
        int n = sz(b);
        FOR(i, 0, n - 1) {
            dp[0][i] = (b[i] == a[0]);
        }
        maxRange[0][0] = dp[0][0];
        FOR(i, 1, n - 1) {
            maxRange[0][i] = max(maxRange[0][i - 1], dp[0][i]);
        }
        FOR(i, 1, m - 1) {
            FOR(j, 0, n - 1) {
                if (a[i] != b[j]) continue;
                if (j == 0) {
                    dp[i][j] = (a[i] == b[j]);
                    maxRange[i][j] = dp[i][j];
                }
                else {
                    FOR(k, 0, i - 1) dp[i][j] = max(dp[i][j], maxRange[k][j - 1] + 1);
                }
                FOR(k, j, n - 1) maxRange[i][k] = max(maxRange[i][k], dp[i][j]);
            }
        }
        int res = 0;
        FOR(i, 0, m - 1) FOR(j, 0, n - 1) res = max(res, maxRange[i][j]);
        return res;
    }
};
