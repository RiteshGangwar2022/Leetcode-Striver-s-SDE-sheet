class MinStack {
public:
    
    stack<long long>st;
    long long mini;
    MinStack() {
        /*
        2nd app=>we will solve it using single loop=> O(1) extra space
          we will take a variable which will store the minimum element, 
          if(st.top()>val), then just ,push the element into stack
          else
          =>we will use formula => 2*val-st.top(), and push it into stack, this integer will act as a boolean variable , so, whenver we return the current minimum element,
          we will update our minimum elemenet with = 2*minimum-st.top()
        */
    }
  void push(int value) {
    long long val = value;
    if (st.empty()) {
      mini = val;
      st.push(val);
    } else {
      if (val < mini) {
        st.push(2 *val*1LL - mini);
        mini = val;
      } else {
        st.push(val);
      }
    }
  }

  void pop() {
    if (st.empty()) return;
    long long el = st.top();
    st.pop();

    if (el < mini) {
      mini = 2 * mini - el;
    }
  }

  int top() {
    if (st.empty()) return -1;

    long long el = st.top();
    if (el < mini) return mini;
    return el;
  }

  int getMin() {
    return mini;
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