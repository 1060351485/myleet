class Solution {
   public:
      vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<vector<int>> rslt;
         sort(nums.begin(), nums.end());
         int n = nums.size();
         for (int i = 0; i < n-3; i++) {
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            if (nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target) continue;
            while (i > 0 && nums[i]==nums[i-1]) i++;
            for (int j = i+1; j < n-2; j++) {
               if (nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
               if (nums[i]+nums[j]+nums[n-1]+nums[n-2] < target) continue;
               while(j > i+1 && nums[j]==nums[j-1]) j++;
               int left = j+1, right = n-1;
               while(left < right) {
                  int sum = nums[i]+nums[j]+nums[left]+nums[right];
                  if(sum < target){
                     left++;

                  }else if(sum > target) {
                     right--;

                  }else{
                     rslt.push_back({nums[i], nums[j], nums[left], nums[right]});
                     left++;right--;
                     while(left > j+1 && nums[left]==nums[left-1]) left++;
                     while(right<n-1 && nums[right]==nums[right+1]) right--;
                  }
               }
            }
         }
         return rslt;
      }
};
