class Solution {
public:
    int romanToInt(string s) {
           int ans=0;
        
        //using map, so ,we can number correspoding to a symbol
        
        unordered_map <char,int> mp{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        
    //TC =>O(s.size())
        //SC =>O(s.size())

    for(int i=0;i<s.size();i++){
        
        //for cases , such as 5 ,10 , 90, 400, 900
        if( i<s.size() && mp[s[i]]<mp[s[i+1]]){
            //for cases such as IV,CM, XL, etc...
            ans=ans-mp[s[i]];
            
            //eg->IV  first ans=-1, then add 5, so ans=4
        }
        else{
            ans=ans+mp[s[i]];
        }
    }
        return ans;
    }
};