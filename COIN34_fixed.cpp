#include <iostream>
#include <algorithm>
#include <utility>

//sort ca 2 + neo 
using namespace std;

pair<int, int> arr[1<<17];
int coins[34];

void calculateCoins() {
	coins[0] = 2;
	coins[1] = 3;
	coins[2] = 5;
	
	for (int i=3; i<34; i++) {
		coins[i] = coins[i-1] + coins[i-2] + coins[i-3];
	}
}

int bs(pair<int, int> arr[], int l, int r, int key) {
	int d = l;
	int c = r;
	while (d<=c) {
		int mid = (d+c)/2;
		if (arr[mid].first >=key) c = mid - 1;
		else d = mid + 1;
	}
	return d;
}

int getBit(int i, int j) {//chi dung cho long int
	return ((i>>(j-1)) & 1);
}

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	return ((a.first < b.first) || (a.first == b.first && a.second>b.second));
}

int maxCoins(int x) {
	int sum;
	int coin;
	int max = -1;
	
	for (int i=0; i< (1<<17); i++) {
		sum = 0;
		coin = 0;
		for (int j=1; j<=17; j++) {
			if (getBit(i,j) == 1) {
				sum += coins[j+17-1];
				coin++;
			}
		}
		arr[i].first = sum;
		arr[i].second = coin;
	}
	
	sort(arr, arr+(1<<17), compare);
	
	for (int i=0; i< (1<<17); i++) {
		coin = 0;
		sum = 0;
		for (int j=1; j<=17; j++) {
			if (getBit(i, j) == 1) {
				coin++;
				sum = sum + coins[j-1];
			}
		}
		if (sum > x) continue;
		if (sum == x)
			if (coin > max) max = coin;
		if (sum < x){
			int index = bs(arr, 0, (1<<17)-1, x-sum);
			if (arr[index].first == (x-sum))
				if (coin + arr[index].second > max) max = coin + arr[index].second;
		}
	}
	return max;	
	
}

int main() {
	int test;
	int x;
	calculateCoins();
	cin >> test;
	for (int i=0; i<test; i++) {
		cin >> x;
		cout <<"Case #" << i+1 << ": " << maxCoins(x) << "\n";
	}
	return 0;
}
