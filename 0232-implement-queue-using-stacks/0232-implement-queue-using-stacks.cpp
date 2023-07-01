class MyQueue {
public:
    stack<int>input,output;
    MyQueue() {
        /* implementing in amortized time complexity =>O(1) and SC=>O(N)
           
           steps=>take two stack
           **for push=>just push element into input stack
           **for pop and top, see output is not emprty perform on top of output
           else , move input ->output
           peroform operation on output
        */
    }
    
    void push(int x) {
        
           input.push(x);
         
    }
    
    int pop() {
         
        if(output.size()==0){
              while(input.size()){
                output.push(input.top());
                input.pop();
             }
            int ans=output.top();
            output.pop();
            return ans;
        }
        else{
            int ans=output.top();
            output.pop();
            return ans;
        
        }
            
    }
    
    int peek() {
          if(output.size()==0){
              while(input.size()){
                output.push(input.top());
                input.pop();
             }
            int ans=output.top();
            return ans;
        }
        else{
            int ans=output.top();
            return ans;
        
        }
    }
    
    bool empty() {
        if((input.size()+output.size())==0){
            return true;
        }
        else{
               return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */