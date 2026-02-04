class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) { 
        if (strs.size() <= 1) {
            return{strs};
        }
        unordered_map<string,vector<string>> map;
        for (auto& s: strs) {
            string key = s;
            sort(key.begin(),key.end());
            map[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto&p : map) {
            result.push_back(p.second);
        }
        return result;

    }
};