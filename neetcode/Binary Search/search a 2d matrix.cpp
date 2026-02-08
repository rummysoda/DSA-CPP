class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        for (int i = matrix.size() - 1; i >= 0;i--) {
            if (target >= matrix[i][0]) {
                row = i;
                break;
            }
        }
            int l = 0;
            int r = matrix[row].size() - 1;
            while ( l <= r) {
                int med = (l+r)*0.5;
                if (target == matrix[row][med]) {return true;}
                if (target > matrix[row][med] ) {
                    l = med +1;
                }
                else {
                    r = med -1;
                }
            }
        
        return false;
    }
};