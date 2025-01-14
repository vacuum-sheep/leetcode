// PQ/Heap 很简单的思路，唯一的问题就是怎么把窗口前面的给pop掉，而解决方法也很粗暴，就是 PQ的element从int变成pair，记录数值的同时记录他们的index。
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        int i{0};
        while (i < k){
            pq.emplace(nums[i], i);
            i++;
        }
        res.push_back(pq.top().first);
        while (i < nums.size()){
            pq.emplace(nums[i], i);
            while (pq.top().second <= i - k) pq.pop();
            res.push_back(pq.top().first);
            i++;
        }
        return res; 
    }
};
