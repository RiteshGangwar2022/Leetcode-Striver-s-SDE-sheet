class Solution {
public:
    bool isAnagram(string s, string t) {
        
       /* TC(n) and SC(n)
         //n=s.size();  m=t.size();
       
       if(s.size()<t.size()){
            return false;
        }
        
        unordered_map<char,int>mp;
        
        for(int i=0;i<s.size();i++){
            
            mp[s[i]]++;
        }
        
        
        for(int i=0;i<t.size();i++){
            
            if(mp.find(t[i])!=mp.end()){
                 
                  mp[t[i]]--;
                
                if(mp[t[i]]==0){
                    mp.erase(t[i]);
                }
            }
            else{
                
                return false;
            }
        }
        
        if(mp.size()!=0){
            return false;
        }
        else{
              return true;
        }*/
        
        //using sorting
        //TC =>O(nlogn + mlongm)
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        if(s==t){
            return true;
        }
        else{
            return false;
        }
      
    }
};