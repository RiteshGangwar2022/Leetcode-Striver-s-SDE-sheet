/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    unordered_map<Node*,Node*>mp;
    
    Node* cloneGraph(Node* node) {
        
        
        //clone a graph using BFS
        //we can using map to store the node which are previouly added in new graph
        //TC=>O(V+E)
        //SC=>O(V)
        
        if(node==NULL){
            return NULL;
        }
         Node*newnode=new Node(node->val,{});
        mp[node]=newnode;
        queue<Node*>q;
        q.push(node);
        
        while(q.size()){

            Node* curr = q.front(); // extract front node
            q.pop(); // pop that from queue
            
            for(auto adj: curr -> neighbors) // now travel in adjcant
            {
                if(mp.find(adj) == mp.end()) // if not present in map
                {
                    mp[adj] = new Node(adj -> val, {}); // then create copy
                    q.push(adj); // push nto the queue
                    
                }
                
                mp[curr] -> neighbors.push_back(mp[adj]); // in current node push adjcant node
            }
               
        }
        return mp[node];
        
    }
};