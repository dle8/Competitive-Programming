#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int n;
int permutation[13];
int factorial[13];

void calFactorial() {
	for (int i=1; i<=n; i++) {
		factorial[i] = 1;
		for (int j=1; j<=i; j++) factorial[i] = factorial[i] * j;
	}
}

void print() {
	for (int i=1; i<=n ; i++) {
		cout << permutation[i] << " ";
	}
}

int smallestFactorial(int p) {
	int result = 0;
	for (int i=1; i<=n; i++) {
		if (factorial[i] <= p) result = i;
	}
	return result;
}

void process2(int p) {
	bool fixed[13];
	bool used[13];
		
	for (int i=1; i<=n; i++) {
		used[i] = false;
		fixed[i] = false;
		permutation[i] = i;
	}
	
	while (p>0) {
		int k = smallestFactorial(p);
		int x = p/factorial[k];
		
		int bien = -1;
		for (int i=permutation[n-k]+1; i<=n; i++) {
			if (!used[i]) {
				bien = i;
				x--;
			}
			if (x==0) break;
		}
		
		permutation[n-k] = bien;
		used[permutation[n-k]] = true;
		fixed[n-k] = true;
		
		//reassign
		int j = 1;
		for (int i=1; i<=n; i++) {
			if (!fixed[i]) {
				while (used[j]) j++;
				permutation[i] = j;
				j++;
			}
		}
		p = p%factorial[k];
	}
	print();
}

void process1(int numbers[]) {
	bool fixed[13];
	bool used[13];
	
	for (int i=1; i<=n; i++) {
		used[i] = false;
		fixed[i] = false;
		permutation[i] = i;
	}

	int numericalOrder = 1;
	for (int i=1; i<=n; i++) {
		if (numbers[i]!=permutation[i]) {
			int addUp = 0;
			for (int j=permutation[i]+1; j<=numbers[i]; j++){
				if (!used[j]) addUp++;				
			}
			numericalOrder += addUp * factorial[n-i];
			
			//reassign
			fixed[i] = true;
			used[numbers[i]] = true;
			permutation[i]= numbers[i];
			
			int j = 1;
			for (int k=1; k<=n; k++) {
				if (!fixed[k]) {
					while (used[j]) j++;
					permutation[k] = j;
					j++;
				}
			}
		}
	}
	
	cout << numericalOrder << "\n";
}

int main() {
	string s;
	int p;
	string input[13];
	int numbers[13];
	string container;
	getline(cin, s);
	n = 0;
	
	/*istringstream iss(s);
	do {
		string subs;
		iss >> subs;
		n++;
		input[n] = subs;
	} while (iss);
	
	n--;//bi thua 1 ptu
	calFactorial();
	
	for (int i=1; i<=n; i++) {
		numbers[i] = stoi(input[i]);
	}*/
	
	istringstream buf(s);
	istream_iterator<string> beg(buf), end;
	vector<string> tokens(beg, end);
	
	for (auto& str: tokens) {
		n++;
		input[n] = str;
	}
	for (int i=1; i<=n; i++) {
		numbers[i] = stoi(input[i]);
	}
	
	calFactorial();
	cin >> p;	
	p--;
	process1(numbers);
	process2(p);
	return 0;
}
