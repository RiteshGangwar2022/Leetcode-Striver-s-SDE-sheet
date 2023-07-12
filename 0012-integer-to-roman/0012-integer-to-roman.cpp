class Solution {
public:
    string intToRoman(int num) {
       
        
        //TC =>O(N) and SC =>O(N)
       vector<int>number{1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string>roman{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    
    
        string ans="";
    /*substraction approach
    for(int i=12;i>=0;i--){
        
          //add string char from roman vector till num is greater than or equal to number vector
           while(num>=number[i]){
               
               ans+=roman[i];
               num-=number[i];
           }
    }
         
        return ans;*/
        
        
        //division approach
         int index=12;
          
        while(num>0){
            
             int newnum=num/number[index];
            
              for(int i=0;i<newnum;i++){
                   ans+=roman[index];
              }
              num=num%number[index];
              index--;
        }
        return ans;
        
    }
};