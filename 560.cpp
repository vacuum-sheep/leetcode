// first, nums[i:j] = nums[:j] - nums[:i], （nums[x:x] = 0, nums[x:x+1] = nums[x]) 这个前缀和的套路你要知道
// then, 我们本质是要找到所有的 (i,j), s.t. nums[i:j] = k, i.e. k = nums[:j] - nums[:i],
// therefore, nums[:i] + k = nums[:j] , 对于每个i， 看看有多少个满足j，但这样写起来会发现是实现不了的， 因为 nums[:i] 是早于nums[:j]得到的。
// so, nums[:j] - k = nums[:i] （1 <= j <= n, 0 <= i < j)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum{{0,1}}; // <sum, count>
        int sum{0}, cnt{0};
        int n = nums.size();
        for (int i{0}; i < n; i++){
            sum += nums[i];
            if (prefixSum.find(sum - k) != prefixSum.end()){
                cnt += prefixSum[sum - k];
            }
            if (prefixSum.find(sum) != prefixSum.end()) prefixSum[sum]++;
            else prefixSum[sum] = 1;
        }
        return cnt;
    }
};
