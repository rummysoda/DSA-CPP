class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (auto& p:tokens) {
           if (p == "+") {
                int f = stack.top();
                stack.pop();
                int d = stack.top();
                stack.pop();
                int x = d + f;
                stack.push(x);
           }
           else if (p == "/") {
                int f = stack.top();
                stack.pop();
                int d = stack.top();
                stack.pop();
                int x = d/f;
                stack.push(x);
           }
           else if (p == "-") {
                int f = stack.top();
                stack.pop();
                int d = stack.top();
                stack.pop();
                int x = d - f;
                stack.push(x);
           }
           else if (p == "*") {
                int f = stack.top();
                stack.pop();
                int d = stack.top();
                stack.pop();
                int x = d*f;
                stack.push(x);
           }
           else {
           int curr = stoi(p);
           stack.push(curr);
           } 
        }
        return stack.top();
    }
};

//gotta udnerstand how that weird calculator works
