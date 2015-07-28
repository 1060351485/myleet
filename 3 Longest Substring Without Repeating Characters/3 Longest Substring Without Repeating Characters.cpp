//
//  3 Longest Substring Without Repeating Characters.cpp
//  
//
//  Created by Apple on 15/7/27.
//
//

class Solution {
public:
    // 60 ms
    int lengthOfLongestSubstring(string s) {
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
    
    
    // use vector instead of hash_map is faster
    // 16 ms
    int lengthOfLongestSubstring(string s) {
        int start = 0, maxCnt = 0;
        // start from i, end at j
        // unordered_map<int, int> m;
        vector<int> v(256, -1);
        for(int i = 0; i < s.length() ; i++){
            if(v[s[i]] != -1){
                if(v[s[i]] >= start)
                    start = v[s[i]] + 1;
            }
            v[s[i]] = i;
            maxCnt = max(i-start+1, maxCnt);
        }
        return maxCnt;
    }
};