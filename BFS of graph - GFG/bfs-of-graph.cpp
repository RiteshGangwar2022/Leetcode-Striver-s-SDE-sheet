//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        
        //TC => O(V+E), as we are tarversing E edges of V vertices
        //SC=>O(V), as we storing at max V no. of vertices
        
        //here, E=total number of edges in graph
        //and V=total nuber of vertices in graph
        vector<int>ans;
        vector<int>vis(V,0);  //intially all are zeros
        queue<int>q;//to store vertices to traverse in level order
        q.push(0);//as first vectices of graph starts from 0
        vis[0]=1;
        while(q.size()){
            
            int temp=q.front();
            q.pop();
            
            ans.push_back(temp);
            
            //iterating vector of every vertices of adjeceny list
            
            for(auto it:adj[temp]){ //means we are iterating vector of vertices of temp vertice
                
                  if(!vis[it]){
                       q.push(it);
                       vis[it]=1;
                  }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends