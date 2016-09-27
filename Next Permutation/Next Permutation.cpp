//
//  Next Permutation.cpp
//  
//
//  Created by Apple on 15/8/18.
//
//

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return;
        // 12345555, this case is covered by next case
        int i;
        for(i = n-1; (nums[i] == nums[i-1])&&(i >= 1); i--); // remove last same ele
        if(i == 0) return;  // all same, no permutation
        if(nums[i] > nums[i-1]){   // bigger than former
            swap(nums[i], nums[i-1]);
            return;
        }
        
        // need iterator to reverse  12531->swap 2 and 3, reverse index 2 to end
        vector<int>::iterator its= nums.end()-1, ite = its;
        for(i = n-1;(nums[i] <= nums[i-1])&&(i>0);i--,its--);
        if(i == 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = n-1;
        while(nums[j] <= nums[i-1]){
            j--;
            ite--;
        }
        if(j != i-1){
            swap(nums[j], nums[i-1]);
            reverse(its, nums.end());
        }else{
            swap(nums[i-1],nums[i+1]);
        }
    }
    
    
    // replace index i, j with its, ite(iterator end)
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return;
        // 12345555, this case is covered by next case
//        int i;
//        for(i = n-1; (nums[i] == nums[i-1])&&(i >= 1); i--); // remove last same ele
//        if(i == 0) return;  // all same, no permutation
//        if(nums[i] > nums[i-1]){   // bigger than former
//            swap(nums[i], nums[i-1]);
//            return;
//        }
        
        // need iterator to reverse
        vector<int>::iterator its= nums.end()-1, ite = its;
        for(;(*its <= *(its-1))&&(its > nums.begin());its--);
        if(its == nums.begin()){
            reverse(its, nums.end());
            return;
        }
        while(*ite <= *(its-1))
            ite--;
        if(ite != its-1){
            swap(*ite, *(its-1));
            reverse(its, nums.end());
        }else
            swap(*(its-1),*(its+1));
    }
    
    // my shortest answer
    void nextPermutation(vector<int>& nums) {
        vector<int>::iterator its= nums.end()-1, ite = its;
        for(;(*its <= *(its-1))&&(its > nums.begin());its--);
        if(its == nums.begin()){
            reverse(its, nums.end());
            return;
        }
        while(*ite <= *(its-1)) ite--;
        swap(*ite, *(its-1));
        reverse(its, nums.end());
    }
    
    // best answer
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return;
        int i = n-1;
        for(;(i >=1)&&(nums[i] <= nums[i-1]); --i);
        reverse(nums.begin()+i, nums.end());
        if(i != 0)
            swap(nums[i-1], *upper_bound(nums.begin()+i, nums.end(), nums[i-1]));
    }
    
    // cheating, stl has nextPermutation in algorithm
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};