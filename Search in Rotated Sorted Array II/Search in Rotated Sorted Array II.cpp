//
//  Search in Rotated Sorted Array II.cpp
//  
//
//  Created by Apple on 15/8/7.
//
//

class Solution {
public:
    
    // 8ms
    bool search(vector<int>& nums, int target) {
        int index = false;
        int st(0), ed(nums.size());
        while (st < ed) {
            int mid = (st + ed)/2;
            if(nums[mid] == target) return true;
            if(nums[st] < nums[ed-1]){
                if(nums[mid] < target){
                    st = mid+1;
                }else{
                    ed = mid;
                }
            }else if((nums[mid] > nums[ed-1])&&(target > nums[ed-1])&&(target < nums[mid])){
                ed = mid;
            }else if((nums[mid] < nums[ed-1])&&(target < nums[st])&&(target > nums[mid])){
                st = mid + 1;
            }else if((nums[mid] < nums[ed-1])&&((target > nums[ed-1])||(target < nums[mid]))){
                ed = mid;
            }else if((nums[mid] > nums[ed-1])&&((target > nums[mid])||(target < nums[st]))){
                st = mid + 1;
            }else if(nums[st] == target){
                return true;
            }else if(nums[ed-1] == target){
                return true;
            }else{
                ed--;
            }
        }
        return index == false?false:true;
    }
};