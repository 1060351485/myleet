//
//  75 Sort Colors.cpp
//  
//
//  Created by Apple on 15/8/2.
//
//

class Solution {
public:
    
    // O(2n)
    void sortColors(vector<int>& nums) {
        int cnt0(0), cnt1(0), cnt2(0), j(0);
        for(int i = 0; i< nums.size(); i++){
            switch (nums[i]){
                case 0:{cnt0++;break;}
                case 1:{cnt1++;break;}
                default:{cnt2++;}
            }
        }
        while(cnt0--)
            nums[j++] = 0;
        while(cnt1--)
            nums[j++] = 1;
        while(cnt2--)
            nums[j++] = 2;
    }
};