class Solution {
public:
    string reverseWords(string s) {
    
        
          string ans="";
        
          int i=s.size()-1;
         while(i>=0){
                
               while(i>=0 && s[i]==' '){
                    i--;             //removing all the trailing spaces
               }
                
                if(i<0){
                    break;
                }
             
               int  j=i;
               
             //now will again move to get word
               while(i>=0 && s[i]!=' '){
                   i--;
               }
             
               if(ans.size()==0){
                     ans+=s.substr(i+1,j-i); //substr(included, excluded) , substr(pos,size)
               }
               else{
                   ans+=" ";
                      ans+=s.substr(i+1,j-i);
               } 
               
         }
        return ans;
    }
};