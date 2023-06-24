class KthLargest {
public:
   //vector<int>ans;
    int m;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        m=k;
        
       /* for(int i=0;i<nums.size();i++){
            
            ans.push_back(nums[i]);
        }*/
        
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            
            if(pq.size()>m){
               pq.pop();
            }
        }
        
        
    }
    
    int add(int val) {
      /* ans.push_back(val);
        sort(ans.begin(),ans.end());
        int size=ans.size();
        
        return ans[size-m];*/
        pq.push(val);
        while(pq.size()>m){
            pq.pop();
        }
       return pq.top();
        
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */