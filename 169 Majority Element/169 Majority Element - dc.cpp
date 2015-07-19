//
//  169 Majority Element - dc.cpp
//  
//
//  Created by Apple on 15/7/19.
//
//

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return (maj(nums, 0, nums.size())).first;
    }
    
    pair<int, int> maj( vector<int>& nums, int st, int ed ){
        pair<int, int> rslt;
        if(ed - st == 1){
            rslt.first = nums[st];
            rslt.second = 1;
            return rslt;
        }
        pair<int, int> a = maj(nums, st, (ed+st)/2);
        pair<int, int> b = maj(nums, (ed+st)/2, ed);
        if(a.first == b.first){
            rslt.first = a.first;
            rslt.second = a.second + b.second;
            return rslt;
        }else{
            int maxValue = (a.second < b.second)? b.first  : a.first ;
            int count = 0;
            for(int i = st; i < ed; i++){
                if(nums[i] == maxValue)
                    count++;
            }
            rslt.first = maxValue;
            rslt.second = count;
            return rslt;
        }
    }
};