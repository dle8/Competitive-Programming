#include <iostream>

using namespace std;
int n;
int a[10000];

void qsort(int arr[], int d, int c) {
	int i, j, mid;
	i = d;
	j = c;
	mid = arr[(d+c)/2];
	
	while (i<=j) {
		while (arr[i] < mid) i++;
		while (arr[j]>=mid) j--;
		if (i>=j) {
			int swap = arr[i];
			arr[i] = arr[j];
			arr[j] = swap;
		} else break;
	}
	
	int swap = arr[(d+c)/2];
	arr[(d+c)/2] = arr[i];
	arr[i] = swap;
	
	if (j>0) qsort(arr, 0, j);
	if (i<n-1) qsort(arr, i, n-1);
}

int main(){
	int k;
	cin >> n >> k;
	
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	qsort(a, 0, n-1);
	
	for (int i=0; i<n; i++) {
		if (i==k) cout <<a[i];
	}
	return 0;
}
