class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<unsigned int, vector<string>> um;
        for (string& s: strs){
            unsigned int sum{0}; // because we use c^4, need unsigned int to prevent int overflow.
            for (char c: s){
                sum += c * c * c * c; // reduce the possibility of collision
            }
            if (um.find(sum) != um.end()){
                um[sum].push_back(s);
            } else {
                um[sum] = {s};
                // um.emplace(sum, {s}); wont work because emplace argument restriction is more tight.
            }
        }
        vector<vector<string>> res;
        for (auto it = um.begin(); it != um.end(); it++){
            res.push_back(it->second);
        }
        // No need as the trick of c^4.
        // vector<vector<string>> res;
        // for (auto it = um.begin(); it != um.end(); it++){
        //     vector<string> vstr{it->second};
        //     unordered_map<int, vector<string>> temp;
        //     for (string s: vstr){
        //         int total{0};
        //         for (int i{0}; i < s.length(); i++){
        //             total += s[i] * s[i];
        //         }
        //         if (temp.find(total) != temp.end()){
        //             temp[total].push_back(s);
        //         } else {
        //             temp[total] = {s};
        //         }
        //         for (auto iter = temp.begin(); iter != temp.end(); iter++){
        //             res.push_back(iter->second);
        //         }
        //     }
        // }
        return res;
    }
};

// other implementation, use sorted string as key.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for (string s: strs){
            string temp{s};
            sort(temp.begin(), temp.end());
            if (um.find(temp) != um.end()){
                um[temp].push_back(s);
            } else {
                um[temp] = {s};
            }
        }
        vector<vector<string>> res;
        for (auto it{um.begin()}; it != um.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};
