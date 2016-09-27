lass Solution {
   public:
      int threeSumClosest(vector<int>& nums, int target) {
         int n = nums.size();
         if (n < 3) return 0;
         sort(nums.begin(), nums.end());
         int gap_rslt = abs(target); 
         for (int i = 0; i < n-3; i++){
            int current = target - nums[i];
            int id1 = i+1, id2 = n-1;
            for (int j = id1; j < id2; j++){
               int gap = current - nums[id1] - nums[id2];
               if (gap == 0)
                return target;
               else{
                  if (abs(gap) < gap_rslt)
                   gap_rslt = gap;
                  if (gap > 0)
                   id1++;
                  else
                   id2--;

               }

            }

         }
         return gap_rslt;

      }

};
