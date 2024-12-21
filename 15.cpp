class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i{0}; i < n - 2; i++){
            // avoid duplicate
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int l{i+1}, r = nums.size() - 1;
            while (l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i],nums[l],nums[r]});
                    // avoid duplicate
                    while (l < r && nums[l] == nums[l+1]) l++;
                    while (l < r && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }
                if (sum < 0) l++;
                if (sum > 0) r--;
            }
        }
        return res;
    }
};
