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
    void postorder(TreeNode*root,vector<int>&ans){
        
        //TC=>O(n)
        /*
        if(root==NULL){

             return;
        }
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);*/
        
        //iterative version
        
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        st1.push(root);
        while(st1.size()){
            
            TreeNode*curr=st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left){
                   st1.push(curr->left);
            
            }
            if(curr->right){
                st1.push(curr->right);
            }
        
        }
        
        while(st2.size()){
            
             TreeNode*top=st2.top();
              st2.pop();
              ans.push_back(top->val);
        }
           
    }
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        if(root==NULL){

           return ans;
        }
        postorder(root,ans);
        return ans;
        
    }
};