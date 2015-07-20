//
//  169 Majority Element - bit manipulation.cpp
//  
//
//  Created by Apple on 15/7/20.
//
//

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = 0, n = nums.size();
        for(int i = 0, mask = 1;i < 32;i++,mask<<=1){
            int count = 0;
            for(int j = 0; j < n;j++){
                if(nums[j]&mask)
                    count++;
                if(count > n/2){
                    maj |= mask;
                    break;
                }
            }
        }
        return maj;
    }
};