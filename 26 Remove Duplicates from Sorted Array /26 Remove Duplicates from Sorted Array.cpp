//
//  26 Remove Duplicates from Sorted Array.cpp
//  
//
//  Created by Apple on 15/6/29.
//
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if( n < 2 )
            return n;
        int i = 0,j = 1;
        for ( j = 1 ; j< n ; j++ ){
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        
        return i+1;
    }
};