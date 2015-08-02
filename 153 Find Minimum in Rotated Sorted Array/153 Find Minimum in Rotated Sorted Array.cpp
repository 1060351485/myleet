//
//  153 Find Minimum in Rotated Sorted Array.cpp
//  
//
//  Created by Apple on 15/8/2.
//
//

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return 0;
        for(int i = 1 ;i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                return nums[i];
            }
        }
        return nums[0];
    }
};