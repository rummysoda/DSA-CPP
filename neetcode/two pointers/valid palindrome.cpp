/*  my first solution i was going to make an unordered set of symbols or unordered set of characters but then i found a function that checks if something
is alphanumeric isalnum*/

class Solution {
public:
    bool isPalindrome(string &s) {
        string clean;

        for (auto& p:s) {
            if (std::isalnum(static_cast<unsigned char>(p))) {
                char c = p;
                c = (char)tolower(c);
                clean.push_back(c);
            }
        }
        auto l = clean.begin();
        auto r = clean.end() - 1;
        while (l < r) {
            if (*r == *l) {
                r--;
                l++;
            }
            else {return false;}
        }
        return true;
    }
};

