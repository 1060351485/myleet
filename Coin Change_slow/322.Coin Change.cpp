int coinChange(vector<int>& coins, int amount) {
	vector<int> rslt(amount+1, 0);
	for (int i = 1; i <= amount; i++){
		coinChange(coins, i, rslt);

	}
	return rslt[amount];

}

void coinChange(vector<int>&coins, int amount, vector<int>& rslt){
	int tempcoins;
	int tempmin = INT_MAX;
	for (int i = 0; i < coins.size(); i++){
		if (amount < coins[i]){
			continue;

		}
		tempcoins = rslt[amount-coins[i]];
		if (tempcoins >= 0 && tempcoins < tempmin)
		  tempmin = tempcoins;

	}
	if (tempmin == INT_MAX)
	  rslt[amount] = -1;
	else
	  rslt[amount] = tempmin + 1;

}
