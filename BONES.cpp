#include <bits/stdc++.h>
#define maxn 60+10
using namespace std;
int a[maxn];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int s1, s2, s3, max, min;
	cin >> s1 >> s2 >> s3;
	for (int i=1; i<=s1; i++) 
		for (int j=1; j<=s2; j++)
			for (int k=1; k<=s3; k++) 
				a[i+j+k]++;
	
	max = -1;
	min = 1000;
	
	for (int i=3; i<=(s1+s2+s3); i++) {
		if (a[i]>max) {
			max = a[i];
			min = i;
		}
		else if (a[i]==max && min>i) min = i;
	}
	
	cout << min;
	return 0;
}
