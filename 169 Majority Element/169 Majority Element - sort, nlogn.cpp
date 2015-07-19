//
//  169 Majority Element - sort, nlogn.cpp
//  
//
//  Created by Apple on 15/7/19.
//
//

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
//        int count = 1;
//        for( int i= 1; i< nums.size(); i++){
//            if(nums[i] == nums[i-1]){
//                count++;
//                if( count > nums.size()/2 )
//                    return nums[i];
//            }else{
//                count = 1;
//            }
//        }
    }
};