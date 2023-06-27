//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool helper(int start, vector<int>&vis, vector<int>adj[]){
        
        
         queue<pair<int,int>>q; //<node,parent>
         vis[start]=1;
         q.push({start,-1});//assuming 0 come from(parent's) is -1
         
         while(q.size()){
             
             auto it=q.front();
             q.pop();
             int node=it.first;
             int parent=it.second;
             
             for(auto it:adj[node]){
                   
                    if(!vis[it]){
                        
                        q.push({it,node});//node will be the parent of all the it values
                        vis[it]=1;
                    }
                    else if(it!=parent){
                        return true;
                    }
             }
         }
         return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        //using BFS traversal 
        //in bfs traversal all the nodes which are at same level added first,
        //so, we can check if a node is already visited ans it does come from its parent then, there is cycle as it is already visited
         //TC =>o(V+E) and SC =>O(V)
         
         vector<int>vis(V,0);
         
         //to traverse all the connecte components
         
         for(int i=0;i<V;i++){
             
             
             if(!vis[i]){
                 
                 if(helper(i,vis,adj)==true){
                     return true;
                 }
             }
         }
         return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends