//
//  Sort Colors.cpp
//  
//
//  Created by Apple on 15/8/3.
//
//

void sortColors(vector<int>& nums) {
    int st(0), ed(nums.size()-1), i(0);
    
    while (nums[st] == 0) // get rid of prefix 000
        st++;
    st = i;
    while (nums[ed] == 2) // get rid of last 222
        ed--;
    
    while (i <= ed) {
        switch (nums[i]) {
            case 0:{
                swap(nums[i++], nums[st++]); // 000110... swap with 1
                break;
            }
            case 2:{
                swap(nums[i], nums[ed--]); // ...2..0112 swap with ed
                break;
            }
            default:{ i++; break;}
        }
    }
}