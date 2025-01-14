// https://www.bilibili.com/video/BV1Qg411q7ia/?spm_id_from=333.337.search-card.all.click&vd_source=bcca157a802b51116b30b09ed7634142
// dp, 前后缀
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> ldp(n);
        vector<int> rdp(n);
        ldp[0] = height[0];
        rdp[n-1] = height[n-1];
        for (int i{1}; i < n; i++){
            ldp[i] = max(ldp[i-1], height[i]);
            rdp[n-1-i] = max(rdp[n-i], height[n-1-i]);
        }

        int sum{0};
        for (int i{0}; i < n; i++){
            sum += min(ldp[i], rdp[i]) - height[i];
        }
        return sum;
    }
};

// double pointer
class Solution {
public:
    int trap(vector<int>& height) {
        int l{0}, r = height.size() - 1, preMax{0}, postMax{0}, sum{0};
        while (l <= r){
            preMax = max(preMax, height[l]);
            postMax = max(postMax, height[r]);
            if (preMax < postMax){
                sum += preMax - height[l];
                l++;
            } else {
                sum += postMax - height[r];
                r--;
            }
        }
        return sum;
    }
};
