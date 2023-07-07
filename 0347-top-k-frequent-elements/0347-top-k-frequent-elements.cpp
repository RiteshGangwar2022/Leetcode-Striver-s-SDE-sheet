class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
          
         vector<int> v;
        unordered_map<int,int> ump;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
        for(int i=0;i<nums.size();i++){
            ump[nums[i]]++;
        }
        for(auto it:ump){
            minh.push({it.second,it.first});
            if(minh.size()>k){
                minh.pop();
            }
        }
        while(minh.size()>0){
            v.push_back(minh.top().second);
            minh.pop();
        }
        return v;
    }
};