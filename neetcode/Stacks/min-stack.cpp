class MinStack {
    int btop;
    int xtop;
    int s[30000];
    int min;
public:
    MinStack() {
        xtop = -1;
        min = 0;
    }
    
    void push(int val) {
        if (xtop >= 30000) {return;}
        s[++xtop] = val;
        if ( (xtop -1) >= 0) {
            if (s[min] > s[xtop]) {min = xtop;}
        }
        
    }
    
    void pop() {
        if (xtop < 0) {return;}
        if (xtop == min ) {
            int newmin = 0;
            for ( int i = 1; i < xtop; i++) {
                if (s[newmin] > s[i]) {
                    newmin = i;
                }
            }
            min = newmin;
        }
        std::cout << s[xtop--];
    }
    
    int top() {
        return s[xtop];
    }
    
    int getMin() {
        return s[min];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 
// i didnt know that we could use a normal stack to implement this.
// so heres the soluoion for a normal stack (nvm too lazy to do it)
// the tehcnique is to have two stacks, one to add numbers and the other to track current minimum

class MinStack {
    stack<int> s,min;
public:
    MinStack() {
    }
    
    void push(int val) {
      s.push(val);
      if (min.empty() || val <= min.top()) {
        min.push(val);
      }
        
    }
    
    void pop() {
        if (min.top() == s.top()) {
            min.pop();
            s.pop();
        }
        else {
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 // min.empty() or x, min,empty() handle first case for the first number to be pushed to the s stack