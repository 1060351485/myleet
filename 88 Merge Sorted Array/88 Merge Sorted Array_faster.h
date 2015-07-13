//
//  88 Merge Sorted Array_faster.h
//  
//
//  Created by Apple on 15/7/13.
//
//

#ifndef __8_Merge_Sorted_Array_faster_h
#define __8_Merge_Sorted_Array_faster_h

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int t = m+n-1;
        int i = m-1, j = n-1;
        while((i >= 0) && (j >= 0)){
            if( nums1[i] > nums2[j] ){
                nums1[t--] = nums1[i--];
            }else{
                nums1[t--] = nums2[j--];
            }
        }
        while( j >= 0 ){
            nums1[t--] = nums2[j--];
        }
    }
};

#endif
