class Solution {
public:
    int strStr(string haystack, string needle) {
        
        
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
        return -1;
    }
};