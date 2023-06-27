class Solution {
public:
    
   /* void dfs(int start,vector<int>&vis,vector<int>adj[]){

           vis[start]=1;
        
           for(auto it:adj[start]){
                   
               if(!vis[it]){

                      dfs(it,vis,adj);
               }
           }
    }
    
    
    void dfs(int row,int col,vector<vector<char>>&grid){
        
        int n=grid.size();
        int m=grid[0].size();
        if(row>=0 && col>=0 && row<n && col<m && grid[row][col]=='1'){
              
            grid[row][col]='0';
            
            //traverse all the eight path
            
            for(int i=-1;i<=1;i++){
                
                for(int j=-1;j<=1;j++){
                    
                    int nrow=row+i;
                    int ncol=col+j;
                    dfs(nrow,ncol,grid);
                }
            }
            
        }
                
     }
    int numIslands(vector<vector<char>>& grid) {
        //simillar to find the number of connected components
        int V=grid[0].size();
        vector<int>adj[V];
        
        //creating adjeaceny list
        for(int i=0;i<grid.size();i++){
            
            for(int j=0;j<grid[i].size();j++){
                
                if(grid[i][j]!=0 &&i!=j){

                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int count=0;
       
        vector<int>vis(V,0);
        
        
        for(int i=0;i<V;i++){
            
            
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }  
        return count;
        
        
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        
         for(int i=0;i<n;i++){

               for(int j=0;j<m;j++){
                   
                   if(grid[i][j]=='1'){
                         count++;
                         dfs(i,j,grid);  
                   }
                      
               }
         }
    
         return count;
    
    }*/
    
     void dfs(int i,int j,vector<vector<char>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && j>=0 && i<n && j<m  && grid[i][j]=='1'){
          
              grid[i][j]='0';
                 dfs(i+1,j,grid);
                 dfs(i,j+1,grid);
                 dfs(i-1,j,grid);
                 dfs(i,j-1,grid);
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
        
    }
};