class Solution {
public:
    int maxArea(vector<int>& height) {
        auto right = height.end() - 1;
        auto left = height.begin();
        int l = *left;
        int r = *right;
        int curr = (distance(left, right)) * (min(r,l));

        while (left < right) {
            if (l < r) {
                left++;
                l = *left;
                int b = (distance(left, right)) * (min(r,l));
                if ( b > curr) {
                    curr = b;
                }
                
            }
            else {
                right--;
                r = *right;
                int b = (distance(left, right)) * (min(r,l));
                if ( b > curr) {
                    curr = b;
                }
            }
        }
        
        return curr;
    }
};

