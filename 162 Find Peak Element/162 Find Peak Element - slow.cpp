//
//  162 Find Peak Element - slow.cpp
//  
//
//  Created by Apple on 15/8/3.
//
//

class Solution {
public:
    int findPeakElement(vector<int>& nums){
        for(int i = 0; i < (int)nums.size()-2;i++){
            if((nums[i] < nums[i+1])&&(nums[i+1] > nums[i+2]))
                return i+1;
        }
        return nums[0]>nums[nums.size()-1]?0:nums.size()-1;
        
    }
};