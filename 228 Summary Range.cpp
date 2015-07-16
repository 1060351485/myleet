//
//  228 Summary Range.cpp
//  
//
//  Created by Apple on 15/7/16.
//
//

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0, first;
        vector<string> V;
        if(!nums.size()) return V;
        else first = nums[0];
        while(i < nums.size()-1){
            if(nums[i+1] - nums[i] != 1){
                if(first != nums[i])
                    V.push_back(to_string(first)+"->"+to_string(nums[i]));
                else
                    V.push_back(to_string(first));
                first = nums[i+1];
            }
            i++;
        }
        if(first == nums[i])  // single element case included
            V.push_back(to_string(first));
        else
            V.push_back(to_string(first)+"->"+to_string(nums[i]));
        return V;
    }
};