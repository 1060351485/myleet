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
    
    void sortColors(int A[], int n) {
        int counts[3] = { 0 }; // 记录每个颜色出现的次数
        for (int i = 0; i < n; i++)
            counts[A[i]]++;
        for (int i = 0, index = 0; i < 3; i++)
            for (int j = 0; j < counts[i]; j++)
                A[index++] = i;
    }
};