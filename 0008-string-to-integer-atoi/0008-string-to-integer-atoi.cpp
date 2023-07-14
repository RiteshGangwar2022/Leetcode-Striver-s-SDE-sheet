class Solution {
public:
    int myAtoi(string s) {
            
        
           if(s.size()==0){
               return 0;
           }
        
           //remove all the trailing zeros
           int i=0;
           while(i<s.size() && s[i]==' '){
                i++; //increase till you find leading zeros
           }
        
           //now, we will get string without leading spaces using substr function
           s=s.substr(i);  //it will string from index i to s.size()
         
           long res=0;
        
        //now, mainting the value of positive or negative
            int sign=1;
           if(s[0]=='-'){
               sign=-1;
           }
        
    
         int mini=INT_MIN;
        int maxi=INT_MAX;
         
         i=(s[0]=='+' || s[0]=='-')?1:0;
           //first element   is positive or negative , then , start trversing string from 1 else from 0 
        
         while(i<s.size()){
             
             
              if(s[0]==' ' || !isdigit(s[i])){
                  
                  break; //if space or current character is not a digit ,then break the loop
              }
             
              res=res*10+ s[i]-'0';
             
              //mainting out of integer condition
              if(sign==-1 && -1*res<=mini){
                  return mini;
              }
              if(sign==1 && 1*res>=maxi){
                  return maxi;
              }
             
              i++;
             
             
         }
        //typecasting to integer and cheking if the number is negative or positve
        return int(res*sign);
           
    }
};