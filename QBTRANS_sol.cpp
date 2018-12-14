#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

int n, m;

int a[111][111];

double d[111];

bool inq[111];

int step[111];



int main() {
	freopen("input.txt", "r", stdin);
	freopen("ans.txt", "w", stdout);
	long test_cases;

	cin >> test_cases;
	for (int current_test = 1; current_test <= test_cases; current_test++) {
		scanf("%d%d", &n, &m);

		memset(a, 0, sizeof(a));
		memset(d, 0, sizeof(d));
		for(int i=0;i<m;++i) {

			int u, v, c;

			scanf("%d%d%d", &u, &v, &c);

			if(a[u][v]==0) a[u][v] = c;

			else a[u][v] = min(a[u][v], c);

		}

		double left = 0, right = 1e7;

		for(int kk=0;kk<40;++kk) {

			double mid = (left+right) / 2;

			queue<int> q;

			for(int i=1;i<=n;++i) d[i] = 0, q.push(i);

			memset( inq, true, sizeof(inq));

			memset( step, 0, sizeof(step));

			bool OK = false;

			while(!q.empty()) {

				int u = q.front(); q.pop();

				inq[u] = false;

				for(int v=1;v<=n;++v) if(a[u][v] > 0 && d[v] > d[u] + a[u][v] - mid) {

					d[v] = d[u] + a[u][v] - mid;

					step[v] = step[u] + 1;

					if(step[v] >= n + 3) {

						OK = true;

						goto lab;

					}

					if(!inq[v]) {

						inq[v] = true;

						q.push(v);

					}

				}

			}

			lab : ;

			if(OK) right = mid;

			else left = mid;

		}

	cout << "Test #" << current_test << ": ";

		if(left > 1e7 - 2) cout << -1 << "\n";

		else printf("%.2f\n", left);
	}
	fclose(stdin);
	return 0;

}
