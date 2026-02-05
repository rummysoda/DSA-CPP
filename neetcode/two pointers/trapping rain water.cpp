class Solution {
public:
    int trap(vector<int>& height) {
        auto r = (height.end() - 1);
        auto l = height.begin();
        int maxL = *l;
        int maxR= *r;
        int sum = 0;

        while(l < r) {
            if (maxL < maxR) {
                l++;
                sum+= std::max(0,(maxL - (*l)));
                if(maxL < (*l)) {maxL = *l;}
            } else {
                r--; 
                sum+= std::max(0,(maxR - (*r)));
                if (maxR < (*r)) {maxR = *r;}
            }
        }
        return sum;

    }
}; 