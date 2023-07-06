class Solution {
public:
    
    
    //it can be implemented by using two loops=>O(n^2), but time complexity increase
    //So, we will use stack , to implement both previoussmaller and next smaller using stack 
    // TC =>o(n) and SC=>O(n)
    void previoussmaller(vector<int>&heights,vector<int>&left){
        
        
        stack<pair<int,int>>s; //<element,index>
        int k=0;
        for(int i=0;i<heights.size();i++){
            
            while(s.size() && s.top().first>=heights[i]){
                
                s.pop();
            }
            if(s.size()==0){
                
                left[k++]=-1;
            }
            else{
                 left[k++]=s.top().second;
            
            }
            s.push({heights[i],i});
        }
       return;
    }
    
    void nextsmaller(vector<int>&heights,vector<int>&right){
        
          stack<pair<int,int>>s;  //<element,index>
      
        int k=heights.size()-1;  
        for(int i=heights.size()-1;i>=0;i--){
            
          while(s.size() && s.top().first>=heights[i]){
                
                s.pop();
            }
            if(s.size()==0){
                
                right[k--]=-1;
            }
            else{
                 right[k--]=s.top().second;
            
            }
            s.push({heights[i],i});
        }
        return;
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
       
        //TLE =>TC =>O(n^2) and SC =>O(1)
     /*   int ans=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int left=i;
           int right=i;
           int ele=heights[i];
         
           for(int x=i-1;x>=0;x--){
                   
               if(heights[x]>=ele){
                   left=x;
               }
               else{
                   break;
               }
                
           }
        
            for(int x=i+1;x<heights.size();x++){
                   
               if(heights[x]>=ele){
                   right=x;
               }
                else{
                     break;
                }
                
           }
           int cal=(right-left+1)*ele;
             ans=max(ans,cal);
        
        }
         return ans;
         
        
        */
        //to reduce time complexity , we will use concept of next smaller to left and next smaller to right , which will store left and right array.
        //now, we can directly calculate ans=right[i]-left[i]-1;
        //so, res=ans*arr[i]
        
        //TC =>O(n) and SC =>O(n)
        
        vector<int>left(heights.size());
        previoussmaller(heights,left);
        
        vector<int>right(heights.size());
        
        nextsmaller(heights,right);
     
        for(int i=0;i<right.size();i++){
             
               if(right[i]==-1){
                   right[i]=heights.size();
               }
        }
        int res=0;
        for(int i=0;i<heights.size();i++){
        
               int temp=right[i]-left[i]-1;
               int ans=temp*heights[i];
               res=max(res,ans);  
        
        }
        return res;
    }
};