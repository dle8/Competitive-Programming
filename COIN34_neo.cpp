#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
pair<int, int> first17[150000], second17[150000];
int coin[34];

void calculateCoins() {
	coin[0] = 2;
	coin[1] = 3;
	coin[2] = 5;
	for (int i=3; i<34; i++) coin[i] = coin[i-1] + coin[i-2] + coin[i-3];
}

bool increase(const pair<int, int>&a, const pair<int, int> &b) {
	return ((a.first < b.first) || (a.first == b.first && a.second > b.second));
}

bool decrease(const  pair<int, int>&a, const pair<int, int>&b) {
	return ((a.first > b.first) || (a.first == b.first && a.second > b.second));
}

bool getBit(int i, int j) {
	return ((i>>(j-1)) & 1);
}

void calSumOfCoins() {
	int sum;
	int numberOfCoins;
	
	for (int i=0; i<(1<<17); i++) {
		sum = 0;
		numberOfCoins = 0;	
		for (int j=1; j<=17; j++) {
			if (getBit(i,j) == 1) {
				sum += coin[j-1];
				numberOfCoins++;
			}
		}
		
		first17[i].first = sum;
		first17[i].second = numberOfCoins;
	}
	
	for (int i=0; i<(1<<17); i++) {
		sum = 0;
		numberOfCoins = 0;
		for (int j=1; j<=17; j++) {
			if (getBit(i,j) == 1) {
				sum += coin[j+17-1];
				numberOfCoins++;
			}
		}
		second17[i].first = sum;
		second17[i].second = numberOfCoins;
	}
	
	sort(first17, first17 + (1<<17), increase);
	sort(second17, second17 + (1<<17), decrease);
}

int maxCoins(int x) {
	int max = -1;
	int val;
	int neo = 0;
	int coin;
	
	for (int i=0; i<(1<<17); i++) {
		if (first17[i].first > x) break;
		if (first17[i].first == x) {
			if (first17[i].second > max ) max = first17[i].second;
		}
		else {
			val = x - first17[i].first;
			coin = first17[i].second;
			for (int j=neo; j<(1<<17); j++) {
				if (second17[j].first > val) continue;
				if (second17[j].first == val) 
					if (second17[j].second + coin > max) {
						max = second17[j].second + coin;
						neo = j;
					}
				if (second17[j].first < val)  {
					neo = j;
					break;	
				}
			}
		}
	}
	
	return max;
}

int main() {
	int test;
	int x;
	
	cin >> test;
	calculateCoins();
	calSumOfCoins();
	for (int i=0; i<test; i++) {
		cin >> x;
		cout << "Case #" << i+1 << ": " << maxCoins(x) << "\n";
	}
	return 0;
}
