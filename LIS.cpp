#include <iostream>

using namespace std;
int f[30000], g[30000];

int bS(int arr[], int length, int key) {
	int l = 0;
	int r = length - 1;
	int mid;
	while (l<=r) {
		mid = (l+r)/2;
		if (arr[mid] >= key) r = mid -1;
		else l = mid + 1;
	}
	return l;
}

int main() {
	int n;
	cin >> n;
	int arr[n];

	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}

	f[0] = arr[0];
	int lengthF = 1;
	g[0] = 1;
	for (int i=1; i<n; i++) {
		int place = bS(f, lengthF, arr[i]);
		g[i] = place+1;
		if (place == lengthF) {
			lengthF++;
			f[place] = arr[i];
		} else {
			if (f[place] > arr[i]) f[place] = arr[i];
		}
	}

	for (int i=0; i<n; i++) cout << i+1 << " " << g[i] << "\n";
	return 0;
}
