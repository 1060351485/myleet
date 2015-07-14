//
//  217 Contain Duplicate-faster.cpp
//  
//
//  Created by Apple on 15/7/14.
//
//

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if( nums.size()==0 )
            return false;
        sort(nums.begin(), nums.end());
        // for( int i = 0; i < nums.size()-1 ;i ++){
        //     if( nums[i] == nums[i+1] )
        //         return true;
        // }
        return unique(nums.begin(),nums.end()) != nums.end();
    }
};