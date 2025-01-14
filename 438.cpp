// 异构 = 同样的长度 + 元素出现的频率相等o。
// 这里动态维护的方法就是出现的 char 就在频率表里减掉，如果到了同样的长度频率表还没有出现负数，那就代表是异构的，如果出现了负数就代表 s[l] 开头的不行, 把 s[l] 减的给加回来， 然后l++
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length();
        vector <int> freq(26);
        vector <int> res;
        for (auto c: p) freq[c - 'a']++;

        int l{0}, r{0};
        while (r < n){
            freq[s[r] - 'a']--;
            while (freq[s[r] - 'a'] < 0){
                freq[s[l] - 'a']++;
                l++;
            }
            if (r - l + 1 == m) res.push_back(l);
            r++;
        } 

        return res;
    }
};
