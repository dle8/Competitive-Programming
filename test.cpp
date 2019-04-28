#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define FORALL(iter, x) for (auto iter = x.begin(); iter != x.end(); iter++)
#define fi first
#define se second
#define sz(x) int(x.size())
typedef pair<int, int> pii;
const int inf = 1e9;

int max(int a, int b) {
    return (a >= b) ? a : b;
}

class Solution {
public:
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        map<int, vector<int>> mymap;
        set<int> myset;
        FOR(i, 0, sz(a) - 1) myset.insert(a[i]);
        FORALL(iter, myset) {
            int num = *iter;
            FOR(i, 0, sz(b) - 1) {
                if (b[i] == num) mymap[num].push_back(i);
            }
        }
        pii dp[500 + 10][3];
        dp[0][0] = {0, -1};
        if (sz(mymap[a[0]]) == 0) {
            dp[0][1] = {0, -1};
        }
        else {
            dp[0][1] = {1, mymap[a[0]][0]};
        }
        for (int i = 1; i <= sz(a) - 1; i++) {
            pii maxConnect = {-inf, inf};
            for (int j = 0; j <= i - 1; j++) {
                if (maxConnect.fi < dp[j].fi) {
                    vector<int>::iterator up = upper_bound(mymap[a[i]].begin(), mymap[a[i]].end(), dp[j].se);
                    if (up == mymap[a[i]].end()) continue;
                    maxConnect = dp[j];
                }
                else if (maxConnect.fi == dp[j].fi && maxConnect.se > dp[j].se) {
                    maxConnect.se = dp[j].se;
                }
            }
            if (maxConnect.fi == -inf) {
                dp[i][0] = {0, -1};
                dp[i][1] = {0, -1};
                continue;
            }
            dp[i][1].fi = maxConnect.fi + 1;
            vector<int>::iterator up = upper_bound(mymap[a[i]].begin(), mymap[a[i]].end(), maxConnect.se);
            dp[i][1].se = *up;
            dp[i][0] = {0, -1};
        }
        int res = 0;
        for (int i = 0; i <= sz(a) - 1; i++) {
            res = max(res, dp[i][1].fi);
        }
        return res;
    }
};
