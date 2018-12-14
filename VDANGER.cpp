#include <iostream>
using namespace std;
int n, m;
int island[11000];
int a[100][100];
int d[100][100];

void floyd() {
	for (int k=0; k<n; k++) 
		for (int i=0; i<n; i++) 
			for (int j=0; j<n; j++) 
				if (d[i][j] > d[i][k] + d[k][j]) 
					d[i][j] = d[i][k] + d[k][j];
}

int main() {
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> island[i];
		island[i]--;	
	}
	island[0] = 0;
	island[m+1] = n-1;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i==j) d[i][j] = 0;
			else d[i][j] = 1000000000;
		}
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			int c;
			cin >> c;
			d[i][j] = c;
		}
	}
	
	floyd();
	int totalCost = 0;
	for (int i=1; i<=m+1; i++) {
		totalCost += d[island[i-1]][island[i]];
	}
	
	cout << totalCost;
	return 0;
}
