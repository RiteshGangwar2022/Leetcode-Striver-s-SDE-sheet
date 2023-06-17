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
    
   /*int height(TreeNode*root){
          
        if(root==NULL){

            return 0;
        }
        
        return max(height(root->left),height(root->right))+1;
    }*/
    
    pair<int,int> helper(TreeNode*root){
        
        if(root==NULL){
            pair<int,int>ans;
            ans={0,0};
            return ans;
        }
        
        pair<int,int>left=helper(root->left);
        pair<int,int>right=helper(root->right);
        
        int ld=left.second;
        int rd=right.second;
        
        int lh=left.first;
        int rh=right.first;
        
         pair<int,int>res;
         res.first=max(lh,rh)+1;
         res.second=max(max(ld,rd),lh+rh);
         return res;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        
        //max diamter can be present on left, right and , both side of the binary tree
        //so, will return max of all the three
        //this will take O(n^2) and Sc=>O(N)
       /* if(root==NULL){
            return 0;
        }
        
        //get diamter from left  part of the tree
        int leftdiameter=diameterOfBinaryTree(root->left);
        //diamter from the right part of the tree
        int rightdiameter=diameterOfBinaryTree(root->right);
        
        //getting maxheight from both left and right
         int lh=height(root->left);
         int rh=height(root->right);
        return max(max(leftdiameter,rightdiameter),lh+rh);*/
        
        //as we are calling two funtion to get the height and traverse to tree
        //we can store that in pair 
         
        //<height,diamter>
        
         pair<int,int>ans=helper(root);
        
           return ans.second;
        
        
    }
};