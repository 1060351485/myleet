//
//  205 Isomorphic String-slow.cpp
//  
//
//  Created by Apple on 15/7/17.
//
//

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int, int> m1, m2;
        for(int i = 0;i < s.length(); i++){
            if((m1.find(s[i]) != m1.end())&&(m2.find(t[i]) != m2.end())){
                if((i- m1[s[i]])!=(i - m2[t[i]]))
                    return false;
            }else if((m1.find(s[i]) == m1.end())&&(m2.find(t[i]) == m2.end())){
            }else
                return false;
            m1[s[i]] = i; m2[t[i]] = i;
        }
        return true;
    }
};