#include <iostream>
#include <algorithm>
#include <utility>
#define maxn 20 + 5
using namespace std;
int n, s;
int t[maxn];
pair<int, int> first10[(1<<10)+100];
pair<int, int> second10[(1<<10)+100];
bool increase(const int&a, const int&b) {
	return (a<b);
}

int getBit(int i, int j) {//lay bit thu j cua i
	return ((i>>(j-1))&1);
}

bool increasePair(const pair<int, int>&a, const pair<int, int>&b) {
	return ((a.first<b.first) || (a.first==b.first && a.second<b.second));
}

bool decreasePair(const pair<int, int> &a, const pair<int, int>&b) {
	return ((a.first>b.first) || (a.first==b.first && a.second<b.second));
}

void process() {
	int mid, sum, numberOfTien;
	mid = n/2;
	for (int i=0; i<(1<<mid); i++) {
		sum = 0;
		numberOfTien = 0;		
		for (int j=1; j<=mid; j++) 
			if (getBit(i,j) == 1) {
				sum+=t[j-1];
				numberOfTien++;
			}
		first10[i].first = sum;
		first10[i].second = numberOfTien;
	}
	
	for (int i=0; i<(1<<(n-mid)); i++) {
		sum = 0;
		numberOfTien = 0;
		for (int j=1; j<=(n-mid); j++)
			if (getBit(i,j) == 1){
				sum+=t[j+mid-1];
				numberOfTien++;
			}
		second10[i].first = sum;
		second10[i].second = numberOfTien;
	}
	
	sort(first10, first10+(1<<mid), increasePair);
	sort(second10, second10+(1<<(n-mid)), decreasePair);
	
//	for (int i=0; i<(1<<mid); i++) cout << first10[i].first << " " << first10[i].second << endl;
//	for (int i=0; i<(1<<(n-mid)); i++) cout << second10[i].first << " " << second10[i].second << endl;
} 

int minTien(int x) {
	int val, totien, min, mid, neo;
	min = 21;
	mid = n/2;
	neo = 0;
	for (int i=0; i<(1<<mid); i++) {
//		cout << first10[i].first << " " << first10[i].second << endl;
		if (first10[i].first > x) break;
		if (first10[i].first == x){
			if (first10[i].second < min) min = first10[i].second;	
		}
		else {
			val = x-first10[i].first;
			totien = first10[i].second;
			for (int j=neo; j<(1<<(n-mid)); j++) {
				if (second10[j].first > val) continue;
				if (second10[j].first == val)
					if ((second10[j].second + totien) < min) {
						min = second10[j].second + totien;
						neo = j;
					}
				if (second10[j].first < val) {
					neo = j;
					break;
				}
			}		
		}
	}
	if (min == 21) return -1;
	return min;
}

int main() {
	cin >> n >> s;
	for (int i=0; i<n; i++) cin >> t[i];
	sort(t, t+n, increase);
	process();
	cout << minTien(s);
}
