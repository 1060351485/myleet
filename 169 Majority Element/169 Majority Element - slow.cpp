//
//  169 Majority Element - slow.cpp
//  
//
//  Created by Apple on 15/7/19.
//
//

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int Size = nums.size();
        int memo[Size] = {0};
        unordered_map<int, int> M;
        memo[0] = nums[0];
        M[nums[0]] = 1;
        for( int i = 1; i< Size ;i++ ){
            if(M.find(nums[i]) == M.end()){
                M[nums[i]] = 1;
                memo[i] = memo[i-1];
            }else{
                M[nums[i]]++;
                if(M[nums[i]] > (i+1)/2)
                    memo[i] = nums[i];
                else
                    memo[i] = memo[i-1];
            }
        }
        return memo[Size-1];
    }
    
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> M;
        for( int i = 0; i< nums.size() ;i++ ){
            if(++M[nums[i]]>nums.size()/2){
                return nums[i];
            }
        }
    }
};