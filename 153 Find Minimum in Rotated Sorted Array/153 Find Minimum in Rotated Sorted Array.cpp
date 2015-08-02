//
//  153 Find Minimum in Rotated Sorted Array.cpp
//  
//
//  Created by Apple on 15/8/2.
//
//

class Solution {
public:
    
    // O(n)
    int findMin(vector<int>& nums) {
        if(nums.empty()) return 0;
        for(int i = 1 ;i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                return nums[i];
            }
        }
        return nums[0];
    }
    
    // binary search, O(logn)
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1, mid;
        if(nums[start] < nums[end]) return nums[start];  // if not rotated, return first one
        while(start != end){
            mid = (start + end)>>1;
            if(nums[mid] < nums[end])
                end = mid;
            else
                start = mid+1;
        }
        return nums[start];
        
    }
    
    //better O(logn)
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1, mid;
        while(start != end){
            if(nums[start] < nums[end])
                return nums[start];  // if not rotated, return first one
            mid = (start + end)>>1;
            if(nums[mid] < nums[end])
                end = mid;
            else
                start = mid+1;
        }
        return nums[start];
    }

};