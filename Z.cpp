/*
Author: Dung Tuan Le
From: University of Rochester
Created: 06/05/2018
*/

//return a vector contains N elements, with lengths equals to the length of string s.
//the i-th element of this vector is the length of the longest prefix of s that starts in s[i]
vector<long> z(string s) {
	long N = s.length();
	long l = r = 0;		
	
	vector<long> ans<N>;
	ans[0] = N;
	FOR(i, 1, N-1) {
		if (i>r) {
			l = i; r = i-1;
			FOR(j, i, N-1) if (s[j-i]==s[j]) r = j; else break;
			ans[i] = r-l+1;
		}
		else {
			long k = i-l;
			if (z[k]<=r[i]) z[i] = z[k];
			else {
				l = i;
				FOR(j, r+1, N-1) if (s[j-i]==s[j]) r = j; else break;
				ans[i] = r-l+1;
			}
		}
	}
}
