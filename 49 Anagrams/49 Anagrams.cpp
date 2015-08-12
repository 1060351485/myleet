//
//  49 Anagrams.cpp
//  
//
//  Created by Apple on 15/8/8.
//
//

class Solution {
public:
    
    // 52ms middle ->40ms fast
    // anagram strings must have same hashcode,so designing hash() function is onr of the most important, we multiply primes here to calculate hashCode
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 107};
    
    int hashCode ( string s ) {
        int h = 1;
        for ( int n = s.length(), i = 0; i < n; i++ )
            h *= primes[s[i]-'a'];
        return h;
    }
    
    vector<string> anagrams(vector<string>& strs) {
        vector<string> rslt;
        unordered_map<int, vector<int>> map;
        for(int i = 0; i< strs.size() ;i++){
            int hc = hashCode(strs[i]);
//            if(map.find(hc) == map.end()){
//                vector<int> v1;
//                map.insert(unordered_map<int, vector<int>>::value_type(hc,v1));
//            }
            map[hc].push_back(i);
        }
        for (unordered_map<int, vector<int>>::iterator i = map.begin() ; i!=map.end();i++)
            if (i->second.size()!=1)
                for (vector<int>::iterator j = i->second.begin(); j!=(i->second).end(); j++)
                    rslt.push_back(strs[*j]);
        return rslt;
    }
    
    
    //48ms
    vector<string> anagrams(vector<string>& strs) {
        vector<string> rslt;
        vector<string> sortStr = strs;
        unordered_map<string, vector<int>> map;
        for(int i = 0; i< strs.size() ;i++){
            sort(sortStr[i].begin(), sortStr[i].end());
            map[sortStr[i]].push_back(i);
        }
        for(unordered_map<string, vector<int>>::iterator i = map.begin(); i != map.end(); i++){
            if(i->second.size()!=1)
                for(int j = 0; j < i->second.size(); j++)
                    rslt.push_back(strs[i->second[j]]);
        }
        return rslt;
    }
    
};