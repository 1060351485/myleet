//
//  Search Range.cpp
//  
//
//  Created by Apple on 15/8/6.
//
//

class Solution {
public:
    
    //12ms O(2logn)
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> rslt(2,-1);
        int n = nums.size();
        int st(0), ed(n), last(0);
        while(st < ed){  // find last
            int mid = (st + ed)/2;
            if((nums[mid] == target)&&((mid == n-1)||(nums[mid+1] > target))){
                rslt[1] = mid;
                ed = mid;
            }
            if(nums[mid] < target)
                st = mid + 1;
            else if(nums[mid] > target)
                ed = mid;
            else if(nums[mid] == target){
                st++;last = mid;
            }
        }
        st = 0, ed = last+1;
        while(st < ed){  // find first
            int mid = (st + ed)/2;
            if((nums[mid] == target)&&((mid == 0)||(nums[mid-1] < target))){
                rslt[0] = mid;
                st = mid + 1;
            }
            if(nums[mid] < target)
                st = mid + 1;
            else if(nums[mid] > target)
                ed = mid;
            else if(nums[mid] == target)
                ed--;
        }
        return rslt;
    }
};