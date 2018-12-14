#include <iostream>
using namespace std;

int max;
bool used[34];
long int coin[34];

void calculateCoins() {
	coin[0] = 2;
	coin[1] = 3;
	coin[2] = 5;
	
	for (int i=3; i<34; i++) 
		coin[i] = coin[i-1] + coin[i-2] + coin[i-3];
}

void init() {
	for (int i=0; i<34; i++) {
		used[i] = false;
	}
}

void buy(int x) {
	if (x==0) {
		int numberOfCoins = 0;
		for (int i=0; i<34; i++) {
			if (used[i]) numberOfCoins++;
		}
		if (numberOfCoins > ::max) ::max = numberOfCoins;
	} else {
		//truong hop neu x k the tong hop duoc bang xu nao thi..?
		for (int i=0; i<34; i++) {
			if (!used[i] && x>=coin[i]) {
				used[i] = true;
				buy(x-coin[i]);
				used[i] = false;
			}
		}
	}
}

int main() {
	calculateCoins();
	int test;
	cin >> test;
	for (int i=0; i<test; i++) {
		int x;
		cin >> x;
		::max = 0;
		init();
		buy(x);
		if (::max == 0) cout << "Case #"<< i+1 << ": " << -1 << "\n";
		else cout <<"Case #" << i+1 << ": " << ::max << "\n";
	}
	return 0;
}
