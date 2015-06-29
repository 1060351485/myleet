//
//  27 Remove Element.cpp
//  
//
//  Created by Apple on 15/6/29.
//
//

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for (int i = 0; i < n; ){
            if( nums[i] == val ){
                swap(nums[i],nums[n-1]);
                n--;
            }else{
                i++;
            }
        }
        return n;
    }
};