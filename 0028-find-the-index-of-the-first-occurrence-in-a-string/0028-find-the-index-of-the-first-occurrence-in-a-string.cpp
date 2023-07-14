class Solution {
public:
    int strStr(string haystack, string needle) {
        
        
        int index=haystack.find(needle);
        
        if(index==-1){
            return -1;
        }
        else{
            return index;
        }
       
        
     /*    TC =>(s*t)
     for(int i=0;i<haystack.size();i++){
            
              if(haystack[i]==needle[0]){
                      int j=i;
                  int index=i;
                  int count=0;
                    for(int i=0;i<needle.size();i++){
                          
                          if(haystack[j]!=needle[i]){
                               break;
                          }
                         j++;
                        count++;
                        
                    }
                  if(count==needle.size()){
                      return index;
                  }
              }
        }
        return -1;*/
        
    }
    
    
        
        //KMP algo TC(s+t)
        /*we will maintain prefix and suffix array which contains the integer value of largest
         prefix and suffix at each index, 
         eg=> string ="abcabcd" 
    prefix and suffix array pi={0,0,0,1,2,3,0};
     
     //way to get prefix array
     int n=str.size();
       vector<int>pi(n);
       TC=>O(n)
       for(int i=0;i<n;i++){
       
            for(int j=0;j<=i;j++){
            
                 //matching first k character and last k character
                if(s.substr(0,j)==s.substr(i-j+1,k)){
                       pi[i]=j;
                }
            }
       }
         return pi;
         
         
         //now, we will optimise time complexity to O(n)
          
          instead of iterating again from index 0 , we will use prefix and suffix array to match substring
          1)while iterating string , we start from j=pi[i-1]; as first index integer=0
          2)now, we will move back in prefixsuffix array till characters not matched
          3)move, j till chracters matched , and last, put j into prefixsuffix array
          
          
          vector<int>pi(n,0);
          
          for(int i=1;i<str.size();i++){
                 
                  int j=pi[i-1];
                  
                   while(j>0 && str[i]!=str[j]){
                         j--;
                   }
                   
                   if(str[i]==str[j]){
                      j++;
                   }
                   pi[i]=j;
          }
          return pi;
         */
    
    
};