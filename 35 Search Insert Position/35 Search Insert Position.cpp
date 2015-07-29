//
//  35 Search Insert Position.cpp
//  
//
//  Created by Apple on 15/7/28.
//
//

class Solution {
public:
    
    // bisearch 8 ms best and worst is logn
    
    int searchInsert(vector<int>& nums, int target) {
        return biSearch(nums, 0, nums.size(), target);
    }
    int biSearch(vector<int>& nums, int st, int ed, int target){
        if(ed - st <= 1)
            return st + (nums[st]<target);
        int mid = (st + ed)/2;
        if(target < nums[mid])
            biSearch(nums, st, mid, target);
        else
            biSearch(nums, mid, ed, target);
    }
};