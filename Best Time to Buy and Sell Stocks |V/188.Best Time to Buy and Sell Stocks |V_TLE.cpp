
// O(nk) time, O(2k) space, got TLE 
int maxProfit(int k, vector<int>& prices) {
	int n = prices.size();
	if (k == 0 || n < 2) return 0;
	if (k > n/2) k = n/2;
	vector<int> release(k, 0);
	vector<int> hold(k, INT_MIN);

	for (int i = 0 ;i < n; i++) {
		for (int j = k-1; j > 0 ; j--){
			release[j] = max(release[j], hold[j]+prices[i]);
			hold[j] = max(hold[j], release[j-1]-prices[i]);
		}
		release[0] = max(release[0], hold[0] + prices[i]);
		hold[0] = max(hold[0], -prices[i]);

	}
	return release[k-1];

}
