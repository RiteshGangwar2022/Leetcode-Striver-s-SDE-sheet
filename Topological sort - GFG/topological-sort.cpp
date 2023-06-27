//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(int start,stack<int>&s,vector<int>&vis,vector<int>adj[]){
	    
	    vis[start]=1;
	    
	    for(auto it:adj[start]){
	        
	        if(!vis[it]){
	            dfs(it,s,vis,adj);
	        }
	    }
	    s.push(start);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    //sorting according to indgree
	    //it is applicable to DAG only(directed acyclic graph)
	    
	    //toposort=> let u->v, means, in toposort , u must appear before v
	    //so, there can be any number of toposort pattern 
	    //TC =>O(V+E)
	    //SC=>O(V)
	    
	  /*  vector<int>indegree(V,0); //intiall indegree of all the vertices is zero
	    //note->to get outdegree, we can just get the size of vector of every indexed array in adjacency list
	    
	    //getting ingree of all the vertices
	    
	    for(int i=0;i<V;i++){
	        
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    //now,push all the elements in queue whose indegree is zero
	    queue<int>q;
	    for(int i=0;i<indegree.size();i++){
	        
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    vector<int>topo;
	    while(q.size()){
	        
	         int node=q.front();
	         q.pop();
	         topo.push_back(node);
	         
	         for(auto it:adj[node]){
	             
	              indegree[it]--;
	              //if indegree of any vertices becomes zero , then ,push it into q
	              if(indegree[it]==0){
	                  q.push(it);
	              }
	         }
	         
	    }
	    return topo;*/
	    
	    
	    
	    //dfs =>simple do a dfs traversal , and store all the vertices in stack 
	    //just insert all the elemnets from stack back to topo vector
	    //same as of BFS
	    vector<int>vis(V,0);
	    stack<int>s;
	    for(int i=0;i<V;i++){
	        
	        if(!vis[i]){
	            dfs(i,s,vis,adj);
	        }
	    }
	    
	   vector<int>topo;
	   while(s.size()){
	       
	       int ele=s.top();
	       s.pop();
	       topo.push_back(ele);
	   }
	    
	    return topo;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends