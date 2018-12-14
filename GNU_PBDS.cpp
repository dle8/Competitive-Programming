#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> Tree;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Tree p;
	p.insert(5);
	p.insert(2);
	p.insert(6);
	p.insert(4);

	//value at 3rd index in sorted array
	cout << *p.find_by_order(3) << endl;

	//index of value 6
	cout << p.order_of_key(6) << endl;

	//7 is not in the set but it will show the index of value 7 in the set
	cout << p.order_of_key(7) << endl;
	return 0;
}
