//
//  198 Hosue Robber.cpp
//  
//
//  Created by Apple on 15/7/21.
//
//

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int *m = new int[nums.size()];
        m[0] = nums[0];
        if(nums.size() == 1)
            return m[0];
        m[1] = nums[1]>nums[0]?nums[1]:nums[0];
        if(nums.size() == 2)
            return m[1];
        //m[i] is maxMoney when go to house i
        for( int i = 2; i < nums.size();i++ ){
            m[i] = max(m[i-1], m[i-2]+nums[i]);
        }
        return m[nums.size()-1];
    }
    
    //      m[i] = max(m[i-1], m[i-2]+nums[i]);
    //for example
    //              9    7    6    3    8    10
    //i             0    1    2    3    4    5
    //m[i]          9    9    15   15   23   25
    //m[i-1]        0    9    7    15   15   15+8
    //m[i-2]+nums   0    7    9+6  9+3  15+8 15+10
    
    
    int rob(vector<int>& nums) {
        int robTemp = 0, noRobTemp = 0, rslt = 0;
        for (int i = 0; i < nums.size(); i++) {
            rslt = max(robTemp, noRobTemp + nums[i]);
            noRobTemp = robTemp;
            robTemp = rslt;
        }
        return rslt;
    }
};