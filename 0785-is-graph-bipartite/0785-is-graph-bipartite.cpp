class Solution {
public:
    
      bool check(int start, int color, vector<int> &vis, vector<vector<int>> &graph){
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
    }
    
   bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
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
        return true;
    }

};