//
//  136 Single Number.cpp
//  
//
//  Created by Apple on 15/7/19.
//
//

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int rslt = 0;
        for(int i = 0 ;i < nums.size(); i++){
            rslt ^= nums[i];
        }
        return rslt;
    }
};