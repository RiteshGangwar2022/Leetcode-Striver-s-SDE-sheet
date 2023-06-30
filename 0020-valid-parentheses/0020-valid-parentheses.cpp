class Solution {
public:
      bool isopening(char ch){
        
        return ch=='(' || ch=='{'  || ch=='[';
    }
    bool matching(char a,char b){
        
        return (a=='('&&b==')') || (a=='['&&b==']') || (a=='{'&&b=='}');
    }
    bool isValid(string x)
    {
        // Your code here
        if(x.length()%2!=0){
            return false;
        }
        //create two function ->1)character matching with bracket fro all opening bracket
        //and another functoin to check matching
        //we will check till the end of string and have three conditoin
        stack<char>s;
        for(int i=0;i<x.size();i++){
            
            char ch=x[i];
            if(isopening(ch)){
                s.push(ch); //if bracket is opening just push the element in stack
            }
            else{
                if(s.size()==0){
                    return false;//chekcing if there is no bracket present in stack to match
                }
                else if(!matching(s.top(),ch)){ 
                    /*if d=current character and top element of stack is not matthing that there is no closing bracket corressponds to that opening bracket ,hence return false*/
                    return false;
                }
                else{
                    s.pop(); //if matching then remove top element of stack
                }
                
            }
        }
        
        //at end if stack becomes empty after all the operation then,just return true;
        if(s.size()==0)   return true;
        return false;
        
    }
};