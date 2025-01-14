class Solution {
private:
    bool isUnique(string s){
        std::unordered_set<char> seen;
        for (char c : s) {
            if (seen.find(c) != seen.end()) {
                return false;  // Character already seen
            }
            seen.insert(c);
        }
        return true;
    }

// 本质上还是double pointer，但不是两边夹，而是一起从左开始慢慢探索
// O(n2)

public:
    int lengthOfLongestSubstring(string s) {
        int l{0}, r{0}, ans{0};
        while (r < s.length()){
            if (isUnique(s.substr(l,r-l+1))){
                ans = r - l + 1;
                r++;
            } else {
                l++;
                r = l + ans;
            }
        }
        return ans;
    }
};

// Improvement on how to determine uniqueness
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int l{0}, r{0}, res{0};
        while (r < s.length()){
            if (us.find(s[r]) == us.end()){
                us.emplace(s[r]);
                res = max(res, r-l+1);
                r++;
            } else {
                us.erase(s[l]);
                l++;
            }
        }
        return res;
    }
};
