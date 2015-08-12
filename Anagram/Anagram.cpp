//
//  Anagram.cpp
//  
//
//  Created by Apple on 15/8/7.
//
//

class Solution {
public:
    
    // 80ms slow
    bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();
        if( m != n ) return false;
        unordered_map<char, int> map;
        for(int i = 0; i < m ;i++){
            if(map.find(s[i]) == map.end())
                map[s[i]] = 1;
            else
                map[s[i]]++;
        }
        for(int j = 0; j < n ;j++){
            if(map.find(t[j])== map.end())
                return false;
            else{
                map[t[j]]--;
                if(map[t[j]] == 0)
                    map.erase(t[j]);
            }
        }
        return map.empty()?true:false;
    }
};