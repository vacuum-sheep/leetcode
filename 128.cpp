class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end()); // 去重
        int maxLen{0};
        for (const auto e: us){
            // 找到连续序列的开头
            if (us.find(e-1) != us.end()) continue;
            int current{e};
            int len{0};
            while (us.find(current) != us.end()){
                len++;
                current++;
            }
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};
