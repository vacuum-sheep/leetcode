// tle
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA{0};
        for (int i{0}; i < height.size(); i++){
            for (int j = i+1; j < height.size(); j++){
                maxA = max(maxA, min(height[i], height[j]) * (j - i));
            }
        }
        return maxA;
    }
};

// 经典的左右pointer向中间收缩
class Solution {
public:
    int maxArea(vector<int>& height) {
        priority_queue<int> pq;
        int left{0}, right{static_cast<int>(height.size()) - 1};
        while (left < right){
            pq.push(min(height[left], height[right]) * (right - left));
            if (height[left] > height[right]) right--; // 应该已经是right来决定了，你left往右移一定只会更小 
            else left++;
        }
        return pq.top();
    }
};

//pq is not necessary
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans{0};
        int left{0}, right{static_cast<int>(height.size()) - 1};
        while (left < right){
            ans = max(ans, min(height[left], height[right]) * (right - left));
            if (height[left] > height[right]) right--; // 应该已经是right来决定了，你left往右移一定只会更小 
            else left++;
        }
        return ans;
    }
}
