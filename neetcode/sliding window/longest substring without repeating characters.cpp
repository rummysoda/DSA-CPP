class Solution {
public:
    int lengthOfLongestSubstring(std::string &s) {
        std::unordered_map<char,int> lt;
        int left = 0;
        int right = 0;
        int longest = 0;
        for (int i = 0; i < s.size(); i ++) {
            char c = s[i];
            if (lt.contains(c) && lt[c] >= left) {
                left = lt[c] + 1;
            }
            lt[c] = i;
            longest = std::max(longest, (i - left + 1));
        }
       return longest;
    }
};