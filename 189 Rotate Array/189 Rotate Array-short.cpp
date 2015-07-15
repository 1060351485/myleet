//
//  189 Rotate Array-short.cpp
//  
//
//  Created by Apple on 15/7/15.
//
//

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        while(k--){
            nums.insert(nums.begin(), nums[nums.size()-1]);
            nums.erase(nums.end()-1);
        }
    }
};