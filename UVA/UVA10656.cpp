#include <bits/stdc++.h>
using namespace std;

#define maxn 1000 + 10
int a[maxn], sum[maxn], max_sum[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
        memset(max_sum, 0, sizeof(max_sum));
        for (int i = n - 1; i >= 1; --i) {
            max_sum[i] = max(max_sum[i + 1], sum[i + 1]);
        }
        max_sum[n] = sum[n];
        int res = 0, left = 0;
        for (int i = 1; i <= n; ++i) {
            if (res < max_sum[i] - sum[i - 1]) {
                res = max_sum[i] - sum[i - 1];
                left = i;
            }
        }
        int cur = 0;
        for (int i = left; i <= n; ++i) {
            cur += a[i];
            cout << a[i];
            if (cur == res) break;
            else cout << " ";
        }
        cout << '\n';
    }
    return 0;
}