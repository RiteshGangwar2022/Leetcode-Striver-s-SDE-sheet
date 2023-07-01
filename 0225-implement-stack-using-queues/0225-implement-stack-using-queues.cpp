class MyStack {
public:
    queue<int>q;
    MyStack() {
        /*2nd app=>using single queue
         //take q and push x into it
         **now, pop all the elements less than size-1    
        */
    }
    
    void push(int x) {
         
          int size=q.size();
        q.push(x);
        
        //now, pop elemnet and push them till size-1
        
        for(int i=0;i<q.size()-1;i++){
                int ans=q.front();
            q.pop();
            q.push(ans);
        
        }
    }
    
    int pop() {
        int ans=q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */