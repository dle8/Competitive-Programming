#include <iostream>
#include <string.h>
using namespace std;

int n, k;
int a[17000+10];

void dequeue() {
	int first, last;
	int queue[17000+10];//mang queue luu chi so, k phai gia tri
	
	first = 1;
	last = 0;

	for (int i=1; i<=k; i++) {
		while (last>=first && a[i]<a[queue[last]]) last--;
		last++;
		queue[last]=i;
	}
	
	cout << a[queue[first]]<< " ";
	
	for (int i=k+1; i<=n; i++) {
		while (last>=first && queue[first]<i-k+1) first++;
		while (last>=first && a[i]<a[queue[last]]) last--;
		last++;
		queue[last]=i;
		cout << a[queue[first]] << " ";
	}
	
	cout << endl;
}

int main() {
	int test;
	//stack min
	cin >> test;
	for (int i=1; i<=test; i++) {
		cin >> n >> k;
		for (int j=1; j<=n; j++) cin >> a[j];
		dequeue();	
	}
	return 0;
}
