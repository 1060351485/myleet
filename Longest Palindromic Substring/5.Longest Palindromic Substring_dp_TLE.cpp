// dp O(N^2) vector got TLE, use * instead, but still got MLE
// O(N^2) space
string longestPalindrome(string s) {
	int n = s.size();

	bool p[n][n];

	int max_id = 0;
	int max_len = 1;

	for (int len = 1; len <= n; len++){
		for (int i = 0; i <= n-len; i++){
			p[i][i+len-1] = 0;
			if (len == 1){
				p[i][i] = 1;
			}else if ((len == 2 || p[i+1][i+len-2] == 1) && s[i] == s[i+len-1]){
				p[i][i+len-1] = 1;
				max_len = len;
				max_id = i;
			}
		}
	}
	return s.substr(max_id, max_len);
}
