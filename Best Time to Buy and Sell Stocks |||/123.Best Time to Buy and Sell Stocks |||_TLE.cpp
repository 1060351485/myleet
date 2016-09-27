// O(N^2) TLE
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	int max = 0;
	for (int i = 0; i < n-1; i++) {
		int temp = maxProfitForOneTrans(prices, 0, i) + maxProfitForOneTrans(prices, i, prices.size());
		max = temp > max?temp:max;
	}
	return max;
}
// [start, end)
int maxProfitForOneTrans(vector<int>& price, int start, int end) {
	if (start >= end) return 0;
	int max = 0;
	int temp_low = price[start];
	for (int i = start; i < end; i++){
		max = price[i]-temp_low > max ? price[i]-temp_low:max;
		temp_low = price[i]<temp_low?price[i]:temp_low;
	}
	return max;
}
