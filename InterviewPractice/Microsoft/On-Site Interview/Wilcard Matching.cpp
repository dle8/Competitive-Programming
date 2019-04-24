// https://leetcode.com/problems/wildcard-matching/

#define sz(x) int(x.size())
class Solution {
public:

    bool isMatch(string s, string p) {
			int cnt = 0;
			for (int i = 0; i < sz(p); i++) {
				if (p[i] == '*') cnt++;
			}
			if (cnt == 0 && sz(s) != sz(p)) return false;
			if (sz(p) - cnt > sz(s)) return false;
			vector<bool> match(sz(s) + 1, false);
			match[0] = true;
			for (int i = 0; i < sz(p); i++) {
				if (p[i] == '*') {
					for (int j = 0; j < sz(s); j++) {
						match[j + 1] = match[j + 1] || match[j];
					}
				}
				else {
					for (int j = sz(s) - 1; j >= 0; j--) {
						match[j + 1] = match[j] && (p[i] == '?' || s[j] == p[i]);
					}
					match[0] = false;
				}
			}
			return match[sz(s)];
    }
};
