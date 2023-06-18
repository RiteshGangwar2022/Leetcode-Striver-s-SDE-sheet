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
      TreeNode* prev=NULL;
public:
    void flatten(TreeNode* root) {
        
        //one approach is to save preorder traversal in a vector and create a link list from it
        //but we cannot create new linked list
        
         //using recursion
        
        if(root==NULL){

            return;
        }
        
        
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
           
    }
};