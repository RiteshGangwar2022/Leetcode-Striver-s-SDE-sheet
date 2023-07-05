class MinStack {
public:
    stack<int>s;
    stack<int>minimum;
    
    MinStack() {
        
        
        /*
        first-app=>use two stack , one will store  all the elements and another will store   minimum element.
        =>we will keep track of minimum element in min stack 
        //TC =>o(1) and SC =>O(2*n)
        */
        
        return;
    }
    
    void push(int val) {
        
        s.push(val);
        if(minimum.size()==0){
               minimum.push(val);
        }
        else if(minimum.top()>=val){
             minimum.push(val);
        }
        return;
    }
    
    void pop() {
        int ans=s.top();
        s.pop();
        if(minimum.top()==ans){
            minimum.pop();
        }
        return;
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minimum.top();
    }
};