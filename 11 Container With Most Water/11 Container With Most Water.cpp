//
//  11 Container With Most Water.cpp
//  
//
//  Created by Apple on 15/8/4.
//
//

class Solution {
public:
    // for example :
    //         3 8 1 1 1 1 2
    //  st   0
    //  ed   6
    // area 12
    // if min Height is 2,
    // the max length that 2 can go is index 0, if ++st, all further rslt should less than temp
    // so ed--, calculate temp area, hold the max height
    
    //O(n)
    
    int maxArea(vector<int>& height) {
        int n = height.size();
        int rslt(0), st(0), ed(n-1),tempHgt(0);
        while(st < ed){
            tempHgt = (height[st] > height[ed])?height[ed--]:height[st++];
            rslt = max(rslt, (ed-st+1)*tempHgt);
        }
        return rslt;
    }
};