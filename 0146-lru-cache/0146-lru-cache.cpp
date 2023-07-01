class LRUCache {
public:
    
    /*least recently used=>any pair which is used first time or before everybody 
     eg=> 1 2 3 4 5 6, if we perform operation on order from 1 to 6
     then ,least recently used will be 1
     
     =>simililarly , we need to complete all the task in O(1)
     
     note=> capacity fn=>intialise the capacity of cache **and when cache becomes full,
     remove the least recently used pair from it and push current pair into cache
     
     
     key =>there key()=>we need to return the value of key if it exist otherwise -1
     put=>we need to put pair<key,value>, but size should not be greater than cache*/

    //to get more see copy or takeuforward channel
    
    class node{
          public:
           int val;
            int key;
            node*next;
            node*prev;
           node(int key,int val){
               this->key=key;
               this->val=val;
           }
    
    };
    
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
    
    int size;
    unordered_map<int,node*>mp;
    
    //to delete node from doubly link list
    void deletenode(node* delnode){
          
        node*delprev= delnode->prev;
        node*delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        
    }
    
    
    //to add node to next of head
    
    void addnode(node* newnode){
        node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
        
    }
       
    LRUCache(int capacity) {
        size=capacity;
        
        //make connectino between head and tail
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
         
        if(mp.find(key)!=mp.end()){
             
            node*res=mp[key];
            int ans=res->val;
            mp.erase(key);
            deletenode(res);
            addnode(res);
            mp[key]=head->next;
            return ans;
            
        } 
        return -1;  
    }
    
    void put(int key, int value) {
         
          if(mp.find(key)!=mp.end()){
              
              node*temp=mp[key];
              mp.erase(key);
              deletenode(temp);
          }
         if(mp.size()==size){
             node*temp=tail->prev;
             mp.erase(tail->prev->key);
             deletenode(temp);
         }
        
        node*res=new node(key,value);
        addnode(res);
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */