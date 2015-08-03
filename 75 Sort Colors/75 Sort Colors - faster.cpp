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
                swap(nums[i--], nums[ed--]); // ...2..0112 swap with ed
                break;
            }
            default:;
        }
        i++;
    }
}

// best solu
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st(0), ed(nums.size()-1);
        for (int i = 0; i <= ed; i++) {
            while ((nums[i] == 2)&&(i < ed))
                swap(nums[i], nums[ed--]);
            while ((nums[i] == 0)&&(i > st))
                swap(nums[i], nums[st++]);
        }
    }
    
     void sortColors(int[] A) {
        int i=-1, j=-1, k=-1;
        for(int p = 0; p < A.length; p++)
        {
            if(A[p] == 0)
            {
                A[++k]=2;
                A[++j]=1;
                A[++i]=0;
            }
            else if (A[p] == 1)
            {
                A[++k]=2;
                A[++j]=1;
                
            }
            else if (A[p] == 2)
            {
                A[++k]=2;
            }
        }
    }
    
};
