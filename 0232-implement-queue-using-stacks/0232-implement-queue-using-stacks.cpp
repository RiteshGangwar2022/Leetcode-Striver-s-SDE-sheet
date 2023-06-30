class MyQueue {
public:
    
    stack<int>input,output;
    MyQueue() {
        //approach one=> use two stack-> input and output.
        //push=> peroform=> input->ouput
                          //x->input
                         // output->input
        //rest perform all the operation on input stack
        //TC ->push O(n), and rest are o(1)
    }
    
    void push(int x) {
        
        while(input.size()){
            
            output.push(input.top());
            input.pop();
        }
        input.push(x);
        while(output.size()){
               input.push(output.top());
            output.pop();
        
        }
         
    }
    
    int pop() {
        
        if(input.empty()){
            return -1;
        }
        int ans=input.top();
        input.pop();
        return ans;
    }
    
    int peek() {
        if(input.empty()){
            return -1;
        }
        int ans=input.top();
        return ans;
    }
    
    bool empty() {
        if(input.size()){
               return false;
        
        }
        else{
            return true;
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