//
//  Search in Rotated Sorted Array.cpp
//  
//
//  Created by Apple on 15/8/7.
//
//

class Solution {
public:
    
    //     8 9 10 11.. 0 1 2 3 ...7
    //          1           3
    int search(vector<int>& nums, int target) {
        int index = -1;
        int st(0), ed(nums.size());
        while (st < ed) {
            int mid = (st + ed)/2;
            if(nums[mid] == target) return mid;
            if(nums[st] <= nums[ed-1]){  // no pivot normal binary search
                if(nums[mid] < target)
                    st = mid+1;
                else
                    ed = mid;
            }else if((nums[mid] > nums[ed-1])&&(target > nums[ed-1])&&(target < nums[mid])){ // left of zone 1
                ed = mid;
            }else if((nums[mid] < nums[ed-1])&&(target < nums[st])&&(target > nums[mid])){  // right of zone 3
                st = mid + 1;
            }else if((nums[mid] < nums[ed-1])&&((target > nums[ed-1])||(target < nums[mid]))){ // right of zone 1
                ed = mid;
            }else if((nums[mid] > nums[ed-1])&&((target > nums[mid])||(target < nums[st]))){  // left of zone 3
                st = mid + 1;
            }else if(nums[st] == target){  // upper option cannot deal with these 2 situation
                return st;
            }else if(nums[ed-1] == target){
                return ed-1;
            }else  // target don't land in to upper section, we don't have it here
                return -1;
        }
        return index;
    }
};