#include <bits/stdc++.h>
#define maxn 1000+10
#include <queue>
using namespace std;

int d[maxn];

struct compare {
	bool operator()(const int&a, const int&b) {
		return d[a]>d[b];
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	priority_queue<int, vector<int>, compare> q;
	d[1] = 2;
	d[2] = 1;
	d[5] = 5;
	q.push(1);
	q.push(2);
	q.push(5);
	while (!q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}
	return 0;
}
