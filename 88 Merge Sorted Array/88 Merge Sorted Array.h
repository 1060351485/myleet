//
//  88 Merge Sorted Array.h
//  
//
//  Created by Apple on 15/7/13.
//
//

#ifndef __8_Merge_Sorted_Array_h
#define __8_Merge_Sorted_Array_h

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, t = 0;
        vector<int> v(nums1);
        while( (i < m)&&(j < n)){
            if(v[i]< nums2[j]){
                nums1[t++] = v[i++];
            }else{
                nums1[t++] = nums2[j++];
            }
        }
        while(i < m)
            nums1[t++] = v[i++];
        while(j < n)
            nums1[t++] = nums2[j++];
    }
};

#endif
