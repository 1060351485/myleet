//
//  213 House Robber II.cpp
//  
//
//  Created by Apple on 15/7/21.
//
//

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int a = nums[0] + robLine(nums, 2, nums.size()-1);
        int b = robLine(nums, 1, nums.size());
        return max(a, b);
    }
    
    int robLine(vector<int>& nums, int st, int ed) {
        int robTemp = 0, noRobTemp = 0, rslt = 0;
        for (int i = st; i < ed; i++) {
            rslt = max(robTemp, noRobTemp + nums[i]);
            noRobTemp = robTemp;
            robTemp = rslt;
        }
        return rslt;
        
    }
};