//
//  136 Single Number-slow.cpp
//  
//
//  Created by Apple on 15/7/19.
//
//

class Solution {
public:
    
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> M;
        for( int i = 0 ; i < nums.size() ; i++ ){
            if(M.find(nums[i]) == M.end())
                M[nums[i]] = 1;
            else
                M[nums[i]] += 1;
        }
        for(auto it = M.begin(); it != M.end(); ++it)
            if(it->second == 1)
                return it->first;
    }
    
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> M;
        for( int i = 0 ; i < nums.size() ; i++ ){
            if(M.find(nums[i]) == M.end())
                M[nums[i]] = 0;
            else
                M.erase(nums[i]);
        }
        return M.begin()->first;
    }
};