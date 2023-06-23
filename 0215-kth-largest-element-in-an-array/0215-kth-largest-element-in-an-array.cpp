class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int>pq;
        for(auto it:nums){
            pq.push(it);
        }
        
        while(pq.size()&&k-1>0){
                
            pq.pop();
            k--;
        
        }
        int ans=pq.top();
        return ans;
    }
};