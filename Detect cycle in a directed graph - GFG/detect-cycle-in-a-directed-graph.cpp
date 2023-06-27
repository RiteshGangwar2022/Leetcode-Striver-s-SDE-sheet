//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int start,vector<int>&vis,vector<int>&pathvis,vector<int>adj[]){
        
        
        vis[start]=1;
        pathvis[start]=1;
        for(auto it:adj[start]){
            
             if(!vis[it]){
                 
                 if(dfs(it,vis,pathvis,adj)==true){
                     return true;
                 }
                
             }
             else if(pathvis[it]!=0){
                    
                     return true;
              }
        }
        pathvis[start]=0; //to traverse from other nodes
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        //for BSF -> since topological sort is applicable on DAG(directed acyclic graph),
        //so, if we apply , toposort on DCG(directed cyclic graph then, it cannot sort all the elements)
        //hence, number of vertices on sorting topo vector , or count of number of vertices is less than V(total number of vertices in graph)
        //just implement topo sort , and check if(count==V) reutrn true else reutrn false;
        // TC =>O(V+E) and SC =>(V)
        
        
        //for  dfs
        //TC =>O(V+E) and SC =>(V)
        
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        
        for(int i=0;i<V;i++){
            
            if(dfs(i,vis,pathvis,adj)==true){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends