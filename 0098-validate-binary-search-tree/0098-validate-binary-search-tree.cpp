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
    
    /*int minimum(TreeNode*root){
        
          if(root==NULL){
               return INT_MAX;
          }
        
          int left=minimum(root->left);
          int right=minimum(root->right);
        return min(root->val,min(left,right));
         
    }
    int maximum(TreeNode*root){
        
        if(root==NULL){
            return INT_MIN;
        }
        
        int left=maximum(root->left);
        int right=maximum(root->right);
        return max(root->val,max(left,right));
    }*/
    
    
    //TC =>O(n) and SC=O(h)
    
    //we are getting maximum node from left and minimum node from right
    bool helper(TreeNode*root,long maxi,long mini){
        
        if(root==NULL){
            
            return true;
        }
        
        if(root->val>maxi&&root->val<mini){
            
            bool left=helper(root->left,maxi,root->val);
            bool right=helper(root->right,root->val,mini);
            
            return left&&right;
        }
        else{
            return false;
        }
        
    }
    bool isValidBST(TreeNode* root) {
        
        //this app->takes TC=>O(n^2), as we are getting min and max for each node and cheking bst for that node
      /*  if(root==NULL){
            return true;
        }
        
        int leftmax=maximum(root->left);
        int rightmin=minimum(root->right);
        if(root->val>=leftmax && root->val<=rightmin &&isValidBST(root->left)&&isValidBST(root->right)){
            return true;
        }
        else{
             return false;
        }*/
        
        //another app->to use range of INT_MIN and INT_MAX
        
        
        return helper(root,LONG_MIN,LONG_MAX);
        
    }
};