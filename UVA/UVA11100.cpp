#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        a.assign(n, 0);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        int max_len = 0, prev = -1, left = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != prev) {
                if (prev != -1) max_len = i - left;
                prev = a[i];
                left = i;
            }
        }
        max_len = max(max_len, n - left);
        cout << max_len << '\n';
        for (int i = 0; i < max_len; ++i) {
            for (int j = i; j < n; j += max_len) {
                if (j > i) cout << " ";
                cout << a[j];
            }
            cout << '\n';
        }
    }
    return 0;
}