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
    
   
    TreeNode* searchBST(TreeNode* root, int val) {
        // TC=>O(logn) and Sc=>O(logn)
        //or TC =>O(h) and SC=>O(h), where, h=height of Binary search tree
        if(root==NULL){
              return NULL;
        }
        if(root->val==val){
            return root;
        }
        //search in left part if root->data<val
        if(root->val>val){
            return searchBST(root->left,val);
        }
        else{
            //else in search in right part
            return searchBST(root->right,val);
        }
    }
};