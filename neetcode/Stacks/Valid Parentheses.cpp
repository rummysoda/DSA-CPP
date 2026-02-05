class Solution {
public:
    bool isValid(string s) {
       if ((s.size() % 2) != 0 ) {return false;}
       stack<char> c;
       unordered_map<char,char> r = {{')','('},{']','['},{'}','{'}};

       for (auto &p :s) {
            if (r.contains(p)) {
                if (!c.empty() && (c.top() == r[p])) {
                    c.pop();
                }
                else {return false;}
            }
            else {
                c.push(p);
            }
       }
        if (c.empty()) {return true;}
        return false;
    }
};