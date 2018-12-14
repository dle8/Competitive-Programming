#include <iostream>
#include <array>
#include <queue>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
	int test;
	cin >> test;
	
	for (int i=0; i<test; i++) {
		int n;
		cin >> n;
		long long totalCost = 0;
		priority_queue< int , vector <int> , greater <int> > pq;
		for (int i=0; i<n; i++) {
			int cost;
			cin >> cost;
			pq.push(cost);
		}
		if (n == 1) cout << 0 << "\n";
		else {
			while (pq.size() != 1) {
				int smallest = pq.top();
				pq.pop();
				int nearSmallest = pq.top();
				pq.pop();
				totalCost += (smallest + nearSmallest);
				pq.push(smallest+nearSmallest);
			}
			cout << totalCost << "\n";
		}
	}
	return 0;
}
