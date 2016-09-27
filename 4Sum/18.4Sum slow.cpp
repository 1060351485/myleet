class Solution {
   public:
      vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<vector<int>> rslt;
         int n = nums.size();
         sort(nums.begin(), nums.end());
         unordered_map<int, vector<pair<int, int>>> m;
         m.reserve(n*n);
         for (int i = 0; i< n-1; i++)
          for(int j = i+1; j < n; j++)
           m[nums[i]+nums[j]].push_back(make_pair(i, j));

         for (int i = 0; i < n-3; i++) {
            while(i > 0 && nums[i]==nums[i-1]) i++;
            for(int j = i+1; j < n-2; j++) {
               while(j > i+1 && nums[j]==nums[j-1]) j++;
               if (m.find(target - nums[i]-nums[j]) != m.end()){
                  vector<pair<int, int>> &v = m[target-nums[i]-nums[j]];
                  bool isFirstPush = true;
                  for (int k = 0; k < v.size(); k++) {
                     if (v[k].first <= j) continue;
                     if (isFirstPush || (rslt.back())[2] != nums[v[k].first]) {
                        rslt.push_back(vector<int>{nums[i], nums[j], nums[v[k].first], nums[v[k].second]});
                        isFirstPush = false;
                     }
                  }
               }
            }
         }
         return rslt;
      }
};
