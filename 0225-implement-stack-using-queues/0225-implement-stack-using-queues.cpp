class MyStack {
public:
    
    queue<int>q1,q2;
    MyStack() {
        /*  1->app=>take two q1, and q2
         follow order while push=>
         **x->q2
         **q1->q2
         **q2->q1
         rest all operation performed on q1 which acts as stack 
         TC =>o(N), and sc=>O(n) 
        
        */
    }
    
    void push(int x) {
        
        q2.push(x);
        
        while(q1.size()){
            q2.push(q1.front());
            q1.pop();
        }
        
       /* while(q2.size()){
            
            q1.push(q2.front());
            q2.pop();
        }*/
        //we can also just swap instead of it
        swap(q1,q2);
        
    }
    
    int pop() {
       int ans=q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        int ans=q1.front();
        return ans;
    }
    
    bool empty() {
        if(q1.size()==0){
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