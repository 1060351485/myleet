//
//  189 Rotate Array.cpp
//  
//
//  Created by Apple on 15/7/15.
//
//

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int n = nums.size();
        int *temp = new int[n-k];
        for(int i = 0 ; i < n-k ;i++)
            temp[i] = nums[i];
        for(int i = n-k ; i < n; i++)
            nums[(i+k)%n] = nums[i];
        for(int i = 0; i < n-k ; i++)
            nums[(i+k)%n] = temp[i];
    }
};