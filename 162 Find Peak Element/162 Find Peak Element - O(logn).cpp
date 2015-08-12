//
//  162 Find Peak Element - O(logn).cpp
//  
//
//  Created by Apple on 15/8/4.
//
//

class Solution {
public:
    
    //     1 2 3 4 5 2
    //  st 0  2  3
    //  ed 5  5  5
    // mid 2  3  4 return 4
    // if mid is a peak, return mid
    // else which side is bigger, go there
    int findPeakElement(vector<int>& nums) {
        int st = 0, ed = nums.size()-1;
        while(ed - st > 1){
            int mid = (st + ed)/2;
            if((nums[mid-1] < nums[mid])&&(nums[mid] > nums[mid+1]))
                return mid;
            else{
                if(nums[mid-1] > nums[mid]){
                    ed = mid;
                }else
                    st = mid;
            }
        }
        return nums[0]>nums[nums.size()-1]?0:nums.size()-1;
        
    }
};