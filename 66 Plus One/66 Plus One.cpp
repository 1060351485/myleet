//
//  66 Plus One.cpp
//  
//
//  Created by Apple on 15/6/30.
//
//

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        for( ; i >= 0; i-- ){
            if( digits[i] == 9 ){
                digits[i] = 0;
            }else{
                digits[i]++;
                return digits;
            }
        }
        //if( i == -1 ){  //no need, if be here,all zero
        digits[0] = 1;
        digits.push_back(0);
        //}
        return digits;
    }
};