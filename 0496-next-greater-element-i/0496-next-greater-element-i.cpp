class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            
              mp[nums2[i]]=i;
        }
        vector<int>ans;
        bool check=true;
        for(int i=0;i<nums1.size();i++){

                     int index=mp[nums1[i]];
                 for(int j=index+1;j<nums2.size();j++){
                        
                        if(nums2[j]>nums1[i]){
                            ans.push_back(nums2[j]);
                            check=false;
                            break;
                        }
                 
                 }
                 if(check){
                     ans.push_back(-1);
                 }
                 check=true;
                  
        }
        return ans;
    }
};