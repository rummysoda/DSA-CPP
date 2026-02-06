class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) { return 0;}
        auto l = prices.begin();
        auto r = prices.begin() + 1;
        int left = *l;
        int right = *r;
        int max= right - left;
        while (r != prices.end()) {
            right = *r;
            if ((right - left) < 0) {
                l = r;
                left = *l;
                r++;
                right = *r;
            }
            else {
                if (max < (right - left)) { max = right - left;}
                r++;
            }
        } 
        return max < 0 ? 0 : max;

    }
};