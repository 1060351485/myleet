//
//  55 Jump Game.cpp
//  
//
//  Created by Apple on 15/7/29.
//
//

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = 0, i = 0;
        while(1){
            // max index can jump to
            maxIdx = max( maxIdx, nums[i]+i );
            if( maxIdx >= nums.size()-1) return true;
            // can only jump to i, return false
            if( maxIdx <= i)
                return false;
            else
                i++; // go to next i, update max index
        }
    }
    
    bool canJump(vector<int>& nums) {
        int maxIdx = 0, i = 0;
        while(maxIdx < nums.size()-1){
            // max index can jump to
            maxIdx = max( maxIdx, nums[i]+i );
            // can only jump to i, return false
            if( maxIdx <= i)
                return false;
            else
                i++; // go to next i, update max index
        }
        return true;
    }
};