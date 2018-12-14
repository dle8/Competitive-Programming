#include <iostream>
#include <cstdio>
#include <algorithm>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
const int N = 222;
using namespace std;
int a[N][N];
int n, k;
 
struct disjoint_set {
    int lab[N];
    disjoint_set()
        {for(int i = 1; i <= n; i++) lab[i] = 0;}
    int root(int u)
        {return lab[u] <= 0 ? u : (lab[u] = root(lab[u]));}
    void join(int u, int v)
        {if (lab[u] > lab[v]) swap(u, v); if (lab[u] == lab[v]) lab[u]--; lab[v] = u;}
};
 
int cnt(int lim) {
    disjoint_set dsu;
    int cc = n;
    for(int i = 1; i <= n; i++)
    for(int j = i + 1; j <= n; j++)
    if (a[i][j] < lim) {
        int x = dsu.root(i), y = dsu.root(j);
        if (x != y) {
            dsu.join(x, y);
            cc--;
        }
    }
    return cc;
}
 
int main() {
//    ios :: sync_with_stdio(0); cin.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    long test_cases;
    
    cin >> test_cases;
    FOR(current_test, 1, test_cases) {
    	cin >> n >> k;
	    for(int i = 1; i <= n; i++)
	        for(int j = 1; j <= n; j++)
	            cin >> a[i][j];
	    int l = 0, r = 1 << 16, m, res = 0;
	    while (l <= r) {
	        m = l + r >> 1;
	        if (cnt(m) >= k) {
	            res = m;
	            l = m + 1;
	        }
	        else
	            r = m - 1;
	    }
	    cout << "Case #" << current_test << ": ";
	    cout << res << "\n";
	}
    return 0;   
}
