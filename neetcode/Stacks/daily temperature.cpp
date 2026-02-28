class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> res(t.size(),0);
        stack<pair<int,int>> stack;
        for (int i =0; i< t.size();i++) {
            int x = t[i];
            while(!stack.empty() && x > stack.top().first) {
                auto pair = stack.top();
                stack.pop();
                res[pair.second] = i - pair.second;
            }
            stack.push({x,i});
        }
        return res;
    }  
};
// o(N) time complexity 

//no pair
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> res(t.size(),0);
        stack<int> stack;
        for (int i =0; i< t.size();i++) {
            while(!stack.empty() && t[stack.top()] < t[i]) {
                res[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        return res;
    }  
};