// best one
int maxProfit(vector<int>& prices) {

	int release2(0), release1(0);
	int hold1(INT_MIN), hold2(INT_MIN);
	for (auto i : prices) {
		release2 = max(release2, hold2+i);
		hold2 = max(hold2, release1-i);
		release1 = max(release1, hold1+i);
		hold1 = max(hold1, -i);
	}
	return release2;
}

// O(N)
// could be shorter
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	if (n < 2) return 0;

	int temp_low = prices[0], temp_max = prices[n-1];

	vector<int>preMax(n);
	vector<int>postMax(n);

	// max one trasaction before day i
	for (int i = 1; i < n; i++){
		preMax[i] = max(preMax[i-1], prices[i]-temp_low);
		temp_low = min(prices[i], temp_low);
	}

	// max one transactoin after day i
	for (int j = n-2; j > 0 ; j--) {
		postMax[j-1] = max(postMax[j], temp_max-prices[j]); 
		temp_max = max(prices[j], temp_max);
	}

	int rslt = 0;

	for (int i = 0; i < n; i++) {
		rslt = max(rslt, preMax[i]+postMax[i]);
	}
	return rslt;
}

// a little shorter
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	if (n < 2) return 0;

	int temp_low = prices[0], temp_max = prices[n-1];

	vector<int>preMax(n, 0);
	vector<int>postMax(n, 0);

	for (int i = 1; i < n; i++){
		// max one trasaction before day i
		preMax[i] = max(preMax[i-1], prices[i]-temp_low);
		temp_low = min(prices[i], temp_low);

		// max one transactoin after day i
		postMax[n-1-i] = max(postMax[n-i], temp_max-prices[n-i]);
		temp_max = max(prices[n-i], temp_max);
	}

	int rslt = 0;

	for (int i = 0; i < n; i++) {
		rslt = max(rslt, preMax[i]+postMax[i]);
	}
	return rslt;
}
