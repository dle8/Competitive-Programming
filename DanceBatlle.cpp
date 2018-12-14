#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	freopen("input5.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	ll test_cases;
	std::cin >> test_cases;

	for(ll current_test = 1; current_test <= test_cases; current_test++){
		ll res = 0;
		ll n, skill;
		std::cin >> skill >> n;

		for(ll i = 0; i < n; i++){
			std::cin >> val[i];
		}
		std::sort(val, val + n);

		ll honor = 0;
		ll l = 0, r = n - 1;

		while(l <= r){
			while(skill > val[l] and l <= r){
				skill -= val[l];
				l += 1;
				honor++;
				res = std::max(res, honor);
			}
			res = std::max(res, honor);
			skill += val[r];
			r -= 1;
			honor -= 1;
			if(honor < 0){
				break;
			}
		}

		std::cout << "Case #" << current_test << ": ";
		std::cout << res << std::endl;
	}
}
