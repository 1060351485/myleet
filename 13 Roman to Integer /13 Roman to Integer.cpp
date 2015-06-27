//
//  13 Roman to Integer.cpp
//  
//
//  Created by Apple on 15/6/27.
//
//

#include <map>

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> T= { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int sum = 0;
        int len = s.length();
        sum += T[s[len-1]];
        while( --len > 0 ){
            if (T[s[len]] <= T[s[len-1]]){
                sum += T[s[len-1]];
            }else{
                sum -= T[s[len-1]];
            }
        }
        return sum;
    }
};