/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void inorder(TreeNode*root, vector<int>&ans){
        
        // TC=>O(N), where n=number of nodes
        //recursive way
        //inorder=> L N R
       /* if(root==NULL){
             return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);*/
        
        stack<TreeNode*>st;
        TreeNode*curr=root;
        while(true){
            
           if(curr!=NULL){
                   st.push(curr);
               curr=curr->left;
           
           }
            else{
                  if(st.size()==0){  //if curr==NULL&&st.size()==0
                      break;
                  }
               curr=st.top();
                st.pop();
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        
        vector<int>ans;
        if(root==NULL){

               return ans;
        }
        inorder(root,ans);
        return ans;
    }
};