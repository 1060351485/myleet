//
//  228 Summary Range-better.cpp
//  
//
//  Created by Apple on 15/7/17.
//
//

class Solution {
public:
    
    //avoid lines outside loop
    
    vector<string> summaryRanges(vector<int>& nums) {
        int size = nums.size();
        vector<string> V;
        if(!size) return V;
        int i = 0,j = 1;
        while(i < size){
            while((j < size)&&(nums[j-1] == nums[j]-1)) j++;
            // instead of cmp values, cmp index, in case of overflow
            if(i < j-1) //  essential!!
                V.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
            else
                V.push_back(to_string(nums[i]));
            i = j;
            j++;
        }
        return V;
    }
    
    // another method
    vector<string> summaryRanges(vector<int>& nums) {
        int size = nums.size();
        vector<string> V;
        int i = 0, iMark = 0;
        while(i < size){
            // i == size-1 essential
            if((i == size-1)||(nums[i+1] > nums[i]+1)){
                V.push_back(to_string(nums[iMark]));
                if(i > iMark) V.back() += "->" + to_string(nums[i]);
                iMark = i+1;
            }
            i++;
        }
        return V;
    }
};