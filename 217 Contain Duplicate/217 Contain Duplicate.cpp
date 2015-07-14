//
//  217 Contain Duplicate.cpp
//  
//
//  Created by Apple on 15/7/14.
//
//

class Solution {
public:
#include <map>
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for ( int i = 0; i < nums.size() ; i++ ){
            if( m.find( nums[i] ) == m.end() ){
                m[nums[i]] = 0;
            }else{
                return true;
            }
        }
        return false;
    }
};