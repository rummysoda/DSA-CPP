class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++) {
            int result = target - nums[i];
            if(map.contains(result)) {return {i, map[result]};}
            map[nums[i]] = i;
        }
        return {0};
    }
};