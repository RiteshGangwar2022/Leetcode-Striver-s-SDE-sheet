class Solution {
public:
    
     /* bool check(int start, int color, vector<int> &vis, vector<vector<int>> &graph){
        vis[start] = color;
        for(auto it:graph[start]){
            if(vis[it] == -1){
                if(!check(it, !color, vis, graph))
                    return false;
            }
            else if(vis[it] == color)
                    return false;
        }
        return true;
    }*/
    
    
    bool bfs(int start,vector<int>&color,vector<vector<int>>&graph){
        
        queue<int> q;
	    q.push(start); 
	    color[start] = 0; 
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop(); 
	        
	        for(auto it : graph[node]) {
	            // if the adjacent node is yet not colored
	            // you will give the opposite color of the node 
	            if(color[it] == -1) {
	                
	                color[it] = !color[node]; 
	                q.push(it); 
	            }
	            // is the adjacent guy having the same color 
	            // someone did color it on some other path 
	            else if(color[it] == color[node]) {
	                return false; 
	            }
	        }
	    }
	    return true; 
    }
   bool isBipartite(vector<vector<int>>& graph) {
       /* int n = graph.size();
        vector<int> vis(n,-1);
       //app=> for a graph to be bipartite ,it cannot have same color on its adjacent vertices
       //so, we can two color and call for dfs call with opposite color on its vertices
       //Tc =>O(V+E) and SC=>O(V)
        for(int i=0;i<n;i++){
            if(vis[i] == -1){
                if(!check(i,0,vis,graph))
                    return false;
            }
        }
        return true;*/
       
       
       //using BFS,=>same app. as above
       //same time and space complexity
       int n=graph.size();
       vector<int>color(n,-1);
       
       for(int i=0;i<n;i++){
           
           if(color[i]==-1){
                 if( bfs(i,color,graph)==false){
                        return false;
                 }
           }
       }
       return true;
    }

};