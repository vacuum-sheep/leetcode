// bubble sort
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i{(int)nums.size()}; i > 0; i--){
            for (int j{0}; j < i; j++){
                if (nums[j] == 0 && j < i - 1){
                    swap(nums[j], nums[j+1]);
                 }
            }
        }
    }
};

//bubble sort with improvement
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
            int cnt{0};
            for (auto e: nums){
                if (e == 0) cnt++;
            }
           for (int i{(int)nums.size()}; i > nums.size() - cnt; i--){
               for (int j{0}; j < i; j++){
                   if (nums[j] == 0 && j < i - 1){
                       swap(nums[j], nums[j+1]);
                    }
               }
          }
      }
};

// double pointer, left 遇到 0 就停下， right 遇到 非0 就停下，如果 left < right 那就互换，然后继续走， 直到结束。
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (left < n && right < n) {
            while (left < n && nums[left] != 0) left++;
            while (right <= left || (right < n && nums[right] == 0)) right++;
            if (right >= n) break;
            swap(nums[left], nums[right]);
        }
    }
};
