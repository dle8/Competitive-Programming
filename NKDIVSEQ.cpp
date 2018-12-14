#include <bits/stdc++.h>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
using namespace std;
using namespace __gnu_pbds;

typedef tree<long, null_type, less<long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n, count, i, j, test_cases;
	srand(time(NULL));

	ofstream fo;
	fo.open("input.txt");
	test_cases = 1+rand()%100;
	fo << test_cases << "\n";
	
	FOR(i, 1, test_cases) {
		fo << 1+rand()%100 << "\n";
	}
	
	fo.close();
	
	ifstream fi;
	fi.open("input.txt");
	fo.open("output.txt");
	fi >> test_cases;
	FOR(current_test, 1, test_cases) {
		fi >> n;
		count = 0;
		j = 1;
		i = 0;
		while (count+j<=n) {
			i++;
			if (i%j!=0) i = ((i/j)+1)*j;
			i+=(j-1)*j;
			count+=j;
			j++;
		}
		
		if (count!=n) {
			if (i%j!=0) i = (i/j+1)*j;
			count++;
			i += (n-count)*j;
		}
		fo << "Case #" << current_test << ": " << i  << ", n =  " << n << "\n";
	} 
	
	fi.close();
	fo.close();
	return 0;
}
