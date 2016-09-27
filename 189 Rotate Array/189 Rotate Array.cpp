//
//  189 Rotate Array.cpp
//  
//
//  Created by Apple on 15/7/15.
//
//

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int n = nums.size();
        int *temp = new int[n-k];
        for(int i = 0 ; i < n-k ;i++)
            temp[i] = nums[i];
        for(int i = n-k ; i < n; i++)
            nums[(i+k)%n] = nums[i];
        for(int i = 0; i < n-k ; i++)
            nums[(i+k)%n] = temp[i];
    }
    
    // O(n) time, O(1) space
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(&nums[0], &nums[n-k]);
        reverse(&nums[n-k], &nums[n]);
        reverse(&nums[0], &nums[n]);
    }
    
    
    // O(1) space
    void leftrotate(vector<int>& nums, int k){
        int n = nums.size();
        if(n < 2 || k == 0) return;
        int temp = nums[0];
        int base(0), sum(0), times(n);
        while (times--) {
            if((sum+k)%n == base){
                nums[sum%n] = temp;
                sum = ++base;
                temp = nums[sum];
            }else{
                nums[sum%n] = nums[(sum+k)%n];
                sum += k;
            }
        }
    }
    
    // from programming pearls, p234
    int gcd(int i, int j){
        while (i != j) {
            if(i > j)
                i -= j;
            else
                j -= i;
        }
        return i;
    }
    
    void leftrotate(vector<int>& nums, int k){
        int n = nums.size();
        if(n < 2 || k == 0) return;
        int temp, j, sum;
        for(int i = 0; i <gcd(k, n); i++ ){
            temp = nums[i];
            j = i;
            while (1) {
                sum = j + k;
                if (sum >= n)
                    sum -= n;
                if(sum == i)
                    break;
                nums[i] = nums[j];
                j = sum;
            }
            nums[j] = t;
        }
    }
    
    // O(1) space
    void rightrotate(vector<int>& nums, int k){
        int n = nums.size();
        if(n < 2 || k == 0) return;
        k %= n;
        int temp = nums[k], form = nums[0];
        int base(0), sum(k), times(n);
        while (times--) {
            if(sum%n == base){
                nums[base] = form;
                sum = ++base;
                form = nums[sum%n];
            }else{
                temp = nums[sum%n];
                nums[sum%n] = form;
                form = temp;
            }
            sum += k;
        }
    }

};