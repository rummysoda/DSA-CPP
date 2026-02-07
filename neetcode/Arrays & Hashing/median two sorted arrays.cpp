class Solution {
public:
    std::vector<int> mergedArray(std::vector<int>& a, std::vector<int> &b) {
        std::vector<int> result;
        result.reserve(a.size()+b.size());
        int i = 0, j = 0;
        while (i < a.size() || j < b.size() ) {
            if (i == a.size()) {
                result.insert(result.cend(),b.cbegin()+j,b.cend());
                break;
            }
            else if(j == b.size()) {
                result.insert(result.cend(),a.cbegin()+i,a.cend());
                break;
            }
            if (a[i] < b[j]) {
                result.push_back(a[i]);
                ++i;
            }
            else {
                result.push_back(b[j]);
                ++j;
            }
        }
        return result;
    }
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> merged = mergedArray(nums1,nums2);
        if (merged.size() % 2 != 0){
            int median = (merged.size() - 1 )/2;
            return merged[median];
        } else {
            int mid = merged.size()/2;
            double sum = (merged[mid] + merged[mid - 1]);
            return sum *0.5;
        }
    }
};