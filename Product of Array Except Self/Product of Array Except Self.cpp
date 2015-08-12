//
//  Product of Array Except Self.cpp
//  
//
//  Created by Apple on 15/8/4.
//
//

// O(n) space
// left save mulitiply before element i
// right ..            after
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n), right(n);
    left[0] = right[n-1] = 1;
    for (int i = 1; i < n; i++) {
        left[i] = left[i-1] *nums[i-1];
        right[n-i-1] = right[n-i]*nums[n-i];
    }
    for (int i = 0; i < n; i++)
        left[i]*=right[i];
    return left;
}

// O(1) space , put right and left together
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> rslt(n,1);
    for (int i = 1; i < n; i++)
        rslt[i] *= rslt[i-1]*nums[i-1];
    int right(1);
    for (int i = n-2; i>=0; i--) {
        right *= nums[i+1];
        rslt[i] *= right;
    }
    return rslt;
}
