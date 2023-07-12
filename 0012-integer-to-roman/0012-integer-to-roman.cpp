class Solution {
public:
    string intToRoman(int num) {
       
        vector<int>number{1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string>roman{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    
    
        string ans="";
    
    for(int i=12;i>=0;i--){
        
        
           while(num>=number[i]){
               
               ans+=roman[i];
               num-=number[i];
           }
    }
         
        return ans;
        
    }
};