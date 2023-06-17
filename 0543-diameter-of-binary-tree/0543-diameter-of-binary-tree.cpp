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
    
    int height(TreeNode*root){
          
        if(root==NULL){

            return 0;
        }
        
        return max(height(root->left),height(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        
        //max diamter can be present on left, right and , both side of the binary tree
        //so, will return max of all the three
        if(root==NULL){
            return 0;
        }
        
        //get diamter from left  part of the tree
        int leftdiameter=diameterOfBinaryTree(root->left);
        //diamter from the right part of the tree
        int rightdiameter=diameterOfBinaryTree(root->right);
        
        //getting maxheight from both left and right
         int lh=height(root->left);
         int rh=height(root->right);
        return max(max(leftdiameter,rightdiameter),lh+rh);
        
    }
};