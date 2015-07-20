//
//  169 Majority Element - moore voting.cpp
//  
//
//  Created by Apple on 15/7/20.
//
//

class Solution {
public:
    // moore voting
    int majorityElement(vector<int>& nums) {
        int rslt = 0, count = 0;
        for( int i = 0; i < nums.size() ; i++ ){
            if((rslt == 0)||(rslt == nums[i])){
                count++;
            }else{
                count--;
                if(count == 0)
                    rslt = 0;
            }
        }
        return rslt;
    }
    
    // moore voting
    int majorityElement(vector<int>& nums) {
        int rslt = nums[0];
        for( int i = 1, count = 1; (i < nums.size())&&(count <= nums.size()/2); i++ ){
            rslt == nums[i]?count++:count--;
            if(count == 0){
                rslt = nums[i];
                count = 1;
            }
        }
        return rslt;
    }
};