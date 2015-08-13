//
//  80 Remove Duplicates from Sorted Array II.cpp
//  
//
//  Created by Apple on 15/8/13.
//
//

class Solution {
public:
    
    
    // 20ms shortest
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int n : nums)
            if(i < 2|| n > nums[i-2])
                nums[i++] = n;
        return i;
    }
    
    
    // mid 20ms
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int i = 1, j = 1, cnt = 1;
        while(j < n){
            if(nums[j] != nums[j-1]){
                cnt = 1;
                nums[i++] = nums[j];
            }else{
                if(cnt < 2)
                    nums[i++] = nums[j];
                cnt++;
            }
            j++;
        }
        return i;
    }
    
    int removeDuplicates(int A[], int n) {
        if (n <= 2)
            return n;
        int rear = 1;
        for(int i = 2; i < n; i++){
            if(!(A[i] == A[rear] && A[i] == A[rear -1])){
                A[++rear] = A[i];
            }
        }
        return rear+1;
    }
    
    // remove K duplicates
    int removeDuplicates(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= k) return n;
        int i = 1, j = 1, cnt = 1;
        while(j < n){
            if(nums[j] != nums[j-1]){
                cnt = 1;
                nums[i++] = nums[j];
            }else{
                if(cnt < k)
                    nums[i++] = nums[j];
                cnt++;
            }
            j++;
        }
        return i;
    }
};