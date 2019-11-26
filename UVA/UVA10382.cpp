#include <bits/stdc++.h>
#define eps 1e-9
using namespace std;

const int maxn = 1e5 + 10;
const int inf = 1e9;
typedef long double ld;
vector<pair<ld, ld>> ranges;

ld max(ld a, ld b) {
    return ((a - b > eps) ? a : b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    double l, w;
    while (cin >> n >> l >> w) {
        ranges.clear();
        for (int i = 1; i <= n; ++i) {
            double x, r;
            cin >> x >> r;
            if (2 * r < w) continue;
            ld d = sqrt(r * r - (w / 2) * (w / 2));
            if (x - d > l || x + d < 0) continue;
            ranges.push_back({max(x - d, 0.0), x + d});
        }
        sort(ranges.begin(), ranges.end(), [](const pair<ld, ld> &p1, const pair<ld, ld> &p2) {
            return p1.first - p2.first < -eps || (p1.first == p2.first && p1.second - p2.second > eps);
        });
        if (ranges.size() == 0 || ranges[0].first > 0) {
            cout << -1 << '\n';
            continue;
        }
        ld farest = ranges[0].second, cur_farest = farest;
        int cnt = 1;
        for (int i = 1; i < ranges.size(); ++i) {
            if (ranges[i].first - farest > eps) break;
            if (ranges[i].first - cur_farest > eps) {
                cur_farest = farest;
                cnt++;
            }
            if (cur_farest >= l) break;
            farest = max(farest, ranges[i].second);
            if (farest >= l) {
                cur_farest = farest;
                cnt++;
                break;
            }
        }
        if (cur_farest >= l) cout << cnt << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}