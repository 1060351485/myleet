//
//  219 Contain Duplicates II.cpp
//  
//
//  Created by Apple on 15/7/17.
//
//

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> M;
        int mark = 0;
        for(int i = 0 ;i < nums.size(); i++){
            if(M.find(nums[i]) == M.end())
                M[nums[i]] = i;
            else{
                mark = M[nums[i]];   //mark is old index, M[nums[i]] is the latest index
                M[nums[i]] = i;
                if(i-mark <= k)
                    return true;
            }
        }
        return false;
    }
    
    class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int,int> M;
            for(int i = 0 ;i < nums.size(); i++){
                if((M.find(nums[i]) != M.end())&&(i-M[nums[i]] <= k))
                    return true;
                M[nums[i]] = i;
            }
            return false;
        }
    };
};