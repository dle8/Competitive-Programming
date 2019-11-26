#include <bits/stdc++.h>
using namespace std;

#define maxn 20 + 10
double m[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int c, s, cnt = 0;
    while (cin >> c >> s) {
        cnt++;
        double total = 0.0, imbalance = 0.0;
        for (int i = 1; i <= s; ++i) {
            cin >> m[i];
            total += m[i];
        }
        cout << "Set #" << cnt << '\n';
        if (s > c) {
            for (int i = s + 1; i <= 2 * c; ++i) m[i] = 0;
            sort(m + 1, m + 1 + 2 * c);
            for (int i = 1; i <= c; ++i) {
                cout << " " << i - 1 << ": ";
                if (m[i] != 0) cout << (int)m[i] << " ";
                if (m[2 * c + 1 - i] != 0) cout << (int)m[2 * c + 1 - i];
                cout << '\n';
                imbalance += abs(m[i] + m[2 * c + 1 - i] - total / c);
            }
        } else {
            for (int i = 1; i <= c; ++i) {
                cout << " " << i - 1 << ": ";
                if (i > s) m[i] = 0;
                if (m[i] != 0) cout << (int)m[i];
                cout << '\n';
                imbalance += abs(m[i] - total / c);
            }
        }
        cout << fixed << setprecision(5) << "IMBALANCE = " << imbalance << '\n';
        cout << '\n';
    }
    return 0;
}