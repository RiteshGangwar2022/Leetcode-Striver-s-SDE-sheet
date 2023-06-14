class Solution {
public:
    int trap(vector<int>& height) {
        
        //TC=>O(n^2)
      /*  int ans=0;
        
        for(int i=0;i<height.size();i++){

        
            int left=i-1;
            int leftmax=0;
            while(left>=0){
                leftmax=max(leftmax,height[left]);
                left--;
            }
            int right=i+1;
            int rightmax=0;
            while(right<height.size()){
                rightmax=max(rightmax,height[right]);
                right++;
            }
            int mini=min(leftmax,rightmax);
            int diff=mini-height[i];
            if(diff>0){
                ans+=diff;
                
            }
        }
        return ans;*/
        int n=height.size();
        int ans=0;
        int left[n];
        int right[n];
          
        
        //creating leftmax array
        int temp=height[0];
        left[0]=temp;
        for(int i=1;i<n;i++){
              
            if(height[i]>temp){
                temp=height[i];
            }
            
            left[i]=temp;
        }
        
        //creating rightmax array
        temp=height[n-1];
        right[n-1]=temp;
        for(int i=n-2;i>=0;i--){
                if(height[i]>temp){
                    temp=height[i];
                }
            right[i]=temp;
        
        }
        
        for(int i=0;i<n;i++){
            
            int mini=min(left[i],right[i]);
            int diff=mini-height[i];
            if(diff>0){
                ans+=diff;
            }
        }
         return ans;
        
    }
};