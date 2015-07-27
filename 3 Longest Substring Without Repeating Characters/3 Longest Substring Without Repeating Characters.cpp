//
//  3 Longest Substring Without Repeating Characters.cpp
//  
//
//  Created by Apple on 15/7/27.
//
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() < 2)
            return s.length();
        int start = 0, maxCnt = 0;
        // start from i, end at j
        unordered_map<int, int> m;
        for(int i = 0; i < s.length() ; i++){
            if(m.find(s[i]) != m.end()){
                if(m[s[i]] >= start)
                    start = m[s[i]] + 1;
            }
            m[s[i]] = i;
            maxCnt = max(i-start+1, maxCnt);
        }
        return maxCnt;
    }
};