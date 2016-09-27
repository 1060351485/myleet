// slow

NumArray(vector<int> &nums) {
	sums.push_back(0);
	for (int i = 0; i < nums.size(); i++)
	  sums.push_back(nums[i] + sums[i]); 
}

int sumRange(int i, int j) {
	return sums[j+1] - sums[i];
}
